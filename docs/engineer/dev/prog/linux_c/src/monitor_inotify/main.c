#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/inotify.h>

void display_event(const char *base, struct inotify_event *event)
{
    char *operate;
    int mask = event->mask;

    if (mask & IN_ACCESS)
        operate = "ACCESS";
    if (mask & IN_ATTRIB)
        operate = "ATTRIB";
    if (mask & IN_CLOSE_WRITE)
        operate = "CLOSE_WRITE";
    if (mask & IN_CLOSE_NOWRITE)
        operate = "CLOSE_NOWRITE";
    if (mask & IN_CREATE)
        operate = "CREATE";
    if (mask & IN_DELETE_SELF)
        operate = "DELETE_SELF";
    if (mask & IN_MODIFY)
        operate = "MODIFY";
    if (mask & IN_MOVE_SELF)
        operate = "MOVE_SELF";
    if (mask & IN_MOVED_FROM)
        operate = "MOVED_FROM";
    if (mask & IN_MOVED_TO)
        operate = "MOVED_TO";
    if (mask & IN_OPEN)
        operate = "OPEN";
    if (mask & IN_IGNORED)
        operate = "IGNORED";
    if (mask & IN_DELETE)
        operate = "DELETE";
    if (mask & IN_UNMOUNT)
        operate = "UNMOUNT";

    printf("%s/%s: %s\n", base, event->name, operate);
}

#define EVENTS_BUF_SIZE 4096

int main(int argc, char const *argv[])
{
    int fd;
    int nbytes, offset;
    char events[EVENTS_BUF_SIZE];
    struct inotify_event *event;

    fd = inotify_init();
    if (fd < 0)
    {
        printf("Failed to initalize inotify\n");
        return -1;
    }

    if (inotify_add_watch(fd, argv[1], IN_ALL_EVENTS) == -1)
    {
        printf("Failed to add file or directory watch\n");
        return -1;
    }

    for (;;)
    {
        memset(events, 0, sizeof(events));

        nbytes = read(fd, events, sizeof(events));
        if (nbytes <= 0)
        {
            printf("Failed to read events\n");
            continue;
        }

        for (offset = 0; offset < nbytes;)
        {
            event = (struct inotify_event *)&events[offset];

            display_event(argv[1], event);

            offset += sizeof(struct inotify_event) + event->len;
        }
    }

    return 0;
}