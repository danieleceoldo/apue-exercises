#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <error.h>
#include <errno.h>


int main(void)
{
    struct utsname buf;

    if (uname(&buf) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");

    printf("sysname: %s\n", buf.sysname);
    printf("nodename: %s\n", buf.nodename);
    printf("release: %s\n", buf.release);
    printf("version: %s\n", buf.version);
    printf("machine: %s\n", buf.machine);
    exit(EXIT_SUCCESS);
}
