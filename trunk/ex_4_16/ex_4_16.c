#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    int i;
    char dirname[NAME_MAX];
    char cwd[PATH_MAX];

    chdir(argv[1]);
    if (chdir(argv[1]) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");

    for (i = 1; ; i++) {

        if (getcwd(cwd, sizeof(cwd)) == NULL)
            error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                    "FATAL ERROR");

        printf("cwd: %s\n", cwd);

        snprintf(dirname, sizeof(dirname), "%d", i);

        if (mkdir(dirname, S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IROTH) < 0)
            error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                    "FATAL ERROR");

        if (chdir(dirname) < 0)
            error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                    "FATAL ERROR");
    }
}
