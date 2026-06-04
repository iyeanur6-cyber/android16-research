#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main() {
    char c[] = "aCfg#&0991.₹_&";
    int fd;
    struct timespec start, end;
    long nanoseconds;

    while (1) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        fd = open("/dev/sec_auth", O_WRONLY);

        if (fd != -1) {
            write(fd, c, strlen(c));
            close(fd);
            break;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        
        nanoseconds = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
        
        if (nanoseconds > 5000) {
            usleep(1000);
        }
    }

    return 0;
}
