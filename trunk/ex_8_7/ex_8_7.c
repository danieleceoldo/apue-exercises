#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
    DIR *dir;
    int fd, fdflag;

    if ((dir = opendir("/")) == NULL)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL");
    
    if ((fd = dirfd(dir)) == -1)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL");
    
    if ((fdflag = fcntl(fd, F_GETFD)) == -1)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL");

    printf("FD_CLOEXEC is %s\n", (fdflag & FD_CLOEXEC) ? "ON" : "OFF");

    closedir(dir);

    if ((fd = open("/", O_RDONLY)) == -1)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL");

    if ((fdflag = fcntl(fd, F_GETFD)) == -1)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL");

    printf("FD_CLOEXEC is %s\n", (fdflag & FD_CLOEXEC) ? "ON" : "OFF");

    exit(EXIT_SUCCESS);
}
