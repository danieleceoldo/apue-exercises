#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

#define FILE_MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

int main(int argc, char* argv[])
{
    int fd;

    if (unlink(argv[1]) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");
    if ((fd = creat(argv[1], FILE_MODE)) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");

    exit(EXIT_SUCCESS);
}
