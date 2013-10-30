#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define BUFFSIZE 4096


int main(int argc, char *argv[])
{
    int fd_in, fd_out;
    int i, sum;
    ssize_t datar, dataw;
    char buff[BUFFSIZE];

    if (argc != 3) {
        printf("Error! Invalid number of arguments.\n");
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd_in = open(argv[1], O_RDONLY)) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL_ERROR");

    if ((fd_out = open(argv[2], O_CREAT|O_TRUNC|O_WRONLY,
                S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL_ERROR");

    do {
        if ((datar = read(fd_in, buff, sizeof(buff))) < 0)
            error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                    "FATAL_ERROR");

        sum = 0;
        for (i = 0; i < datar; i++)
            sum += buff[i];
        if (sum != 0) 
            if ((dataw = write(fd_out, buff, datar)) != datar)
                if (dataw < 0)
                    error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                            "FATAL_ERROR");
                else
                    error_at_line(EXIT_FAILURE, 0, __FILE__, __LINE__,
                            "WRITE DATA LESS THAN EXPECTED.");

    } while (datar != 0);

    exit(EXIT_SUCCESS);
}
