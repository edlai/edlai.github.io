// https://www.itread01.com/content/1541317627.html

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

sem_t sem;

void* change_resource(void *res)
{
    char *msg = (char*)res;

    printf("1111");
    while (1) {
        sem_wait(&sem);
        strcat(msg, "a");
        printf("resource changed with value: %s\n", msg);
    }
}

int main()
{
  pthread_t thread;
  void *resource;

    int ret = sem_init(&sem, 0, 0);
    if (ret == -1) {
        printf("sem_init failed \n");
        return -1;
    }

    ret = pthread_create(&thread, NULL, change_resource, (void*)resource);
    if (ret != 0) {
        printf("pthread_create failed \n");
        return -1;
    }

    while (1) {
        sem_post(&sem);
        sleep(1);
    }
}