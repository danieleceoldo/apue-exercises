#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>

void call_vfork(void)
{
    pid_t pid;

    if ((pid = vfork()) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");
    if (pid == 0) {
        printf("Child here\n");
    } else {
        printf("Parent here: child terminated\n");
    }

    return;
}


int main(void)
{
    call_vfork();

    printf("after vfork\n");

    exit(EXIT_SUCCESS);
}
