  GNU nano 9.0       x.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char c[] = "aCfg#&0991.₹_&";
    int fd = open("/dev/sec_auth", O_WRON>

    if (fd != -1) {
        write(fd, c, strlen(c));
        close(fd);
    }

    return 0;
}


