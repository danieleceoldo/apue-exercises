#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>


int main(void)
{
    pid_t pid;

    setbuf(stdout, NULL);

    if ((pid = fork()) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL");

    if (pid > 0) {
        sleep(2);
        system("ps aux");
    }

    exit(EXIT_SUCCESS);
}
