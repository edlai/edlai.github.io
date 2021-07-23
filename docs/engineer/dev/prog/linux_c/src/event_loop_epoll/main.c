// https://iter01.com/577425.html
// https://zhuanlan.zhihu.com/p/361750240
// https://segmentfault.com/a/1190000003063859

/*
int epoll_create(int size); 創建一個 epoll 對象
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event); 向 epoll 對象中添加要管理的連接
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout); 等待其管理的連接上的 IO 事件
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/epoll.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define MAX_EVENTS 10

void handle_time(int fd)
{
  int time_len = 0;
  struct tm *tm_info;
  struct timeval tv;
  char log_buff[256] = {0};

  printf("%lu [%d:%s()]\n", time(0), __LINE__, __func__);

  write(fd, "HTTP/1.0 200 OK\r\n\r\n", 19);

  gettimeofday(&tv, NULL);
  tm_info = localtime(&tv.tv_sec);
  time_len += strftime(log_buff, sizeof log_buff, "20%y-%m-%d %H:%M:%S", tm_info);
  time_len += snprintf(log_buff + time_len, sizeof log_buff - time_len, ".%03ld ", tv.tv_usec / 1000);
  write(fd, log_buff, strlen(log_buff));
}

// 處理get請求
void handle_get(int fd, char path[])
{
  printf("%lu [%d:%s()]\n", time(0), __LINE__, __func__);
  char buf[1024];
  int n;
  int filefd;

  if ((filefd = open(path + 1, O_RDONLY)) == -1)
  {

    write(fd, "HTTP/1.0 404 Not Found\r\n\r\n", 26);
    return;
  }
  write(fd, "HTTP/1.0 200 OK\r\n\r\n", 19);

  while ((n = read(filefd, buf, sizeof(buf))) > 0)
  {
    write(fd, buf, n);
  }

  close(filefd);
}

// 非阻塞設定
void setnonblocking(int fd)
{
  int opts;
  opts = fcntl(fd, F_GETFL);
  if (opts < 0)
  {
    perror("fcntl(sock,GETFL)");
    exit(1);
  }
  opts = opts | O_NONBLOCK;
  if (fcntl(fd, F_SETFL, opts) < 0)
  {
    perror("fcntl(sock,SETFL,opts)");
    exit(1);
  }
}

int main(int ac, char *av[])
{

  int i;
  int n;
  struct sockaddr_in addr;
  char buf[1024] = {0};
  char cmd[512] = {0};
  char path[512] = {0};
  int sockfd;

  if (ac < 2)
  {
    printf("Usage: %s port_num\n", av[0]);
    exit(1);
  }

  struct epoll_event ev, events[MAX_EVENTS];
  int listen_sock, conn_sock, nfds, epollfd;

  signal(SIGPIPE, SIG_IGN);

  listen_sock = socket(AF_INET, SOCK_STREAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(av[1]));
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(listen_sock, (const struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
  {
    perror("cannot bind");
    exit(1);
  }

  listen(listen_sock, 1);

  // 建立 epoll 例項
  epollfd = epoll_create(10);
  if (epollfd == -1)
  {
    perror("epoll_create");
    exit(EXIT_FAILURE);
  }
  // 註冊 socket 檔案描述符
  ev.events = EPOLLIN;
  ev.data.fd = listen_sock;
  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1)
  {
    perror("epoll_ctl: listen_sock");
    exit(EXIT_FAILURE);
  }

  printf("[%d:%s()] \n", __LINE__, __func__);

  while (1)
  {
    printf("%lu [%d:%s()] nfds=%d \n", time(0), __LINE__, __func__, nfds);

    // TIP: 可以用於等待IO事件。如果當前沒有可用的事件，這個函數會阻塞調用線程。
    nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);

    printf("%lu [%d:%s()] nfds=%d \n", time(0), __LINE__, __func__, nfds);

    if (nfds == -1)
    {
      perror("epoll_pwait");
      exit(EXIT_FAILURE);
    }

    for (n = 0; n < nfds; ++n)
    {
      printf("%lu [%d:%s()] >>> nfds=%d \n", time(0), __LINE__, __func__, nfds);

      // 主socket通過accept獲取客戶端與伺服器之間的socket檔案描述符並註冊到epoll例項
      if (events[n].data.fd == listen_sock)
      {
        // 註冊客戶端與伺服器之間的socket檔案描述符
        conn_sock = accept(listen_sock, NULL, NULL);
        if (conn_sock == -1)
        {
          perror("accept");
          exit(EXIT_FAILURE);
        }
        setnonblocking(conn_sock);
        ev.events = EPOLLIN | EPOLLET; // 處理的事件型別為EPOLLIN
        ev.data.fd = conn_sock;
        if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
        {
          perror("epoll_ctl: conn_sock");
          exit(EXIT_FAILURE);
        }
      }
      else
      { // 客戶端與伺服器之間的socket檔案描述符用於讀取客戶端GET請求(EPOLLIN)
        sockfd = events[n].data.fd;
        if ((i = read(sockfd, buf, sizeof(buf))) <= 0)
        {
          close(sockfd);
        }
        else
        {
          sscanf(buf, "%s%s", cmd, path);
          if (strcmp(cmd, "GET") == 0 && (path))
          {
            char *pch;
            pch = strstr(path, "/api/time");
            if (pch != NULL)
            {
              printf("[%d:%s()] cmd(%p): %s %s\n", __LINE__, __func__, cmd, cmd, path);
              handle_time(sockfd);
            }
            else
            {
              handle_get(sockfd, path);
            }
          }

          else
          {
            printf("[%d:%s()] cmd(%p): %s\n", __LINE__, __func__, cmd, cmd);
          }
          close(sockfd); //close the sockfd
        }
      }
    }
    printf("[%d:%s()] \n", __LINE__, __func__);
  }
  return 0;
}

/*
Run:
$ ./a.out 8081

Test:
$ ab -n 10000 -c 1000 http://172.17.2.205:8081/api/time
*/