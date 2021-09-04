#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

void log2syslog(char *process_name, int level, char *msg)
{
  openlog(process_name, LOG_CONS | LOG_PID, LOG_USER);
  syslog(LOG_USER | level, "%s", msg);
  closelog();
}

int main(int argc, char *argv[])
{

  int level = 0;

  log2syslog(argv[0], level, "===============================\n");
  while (level < 8)
  {
    char msg[256] = {0};
    snprintf(msg, 256, "%d", level);

    log2syslog(argv[0], level, msg);

    level++;
  }
  log2syslog(argv[0], level, "===============================\n");

  return 0;
}
