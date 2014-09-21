#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <limits.h>


int main(void)
{
    char buf[BUFSIZ];
    //setbuf(stdout, buf);
    /*
    if (setvbuf(stdout, buf, _IONBF, BUFSIZ) != 0)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
    */
    setvbuf(stdout, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
    
    printf("Hello World!\n");

    sleep(10);

    exit(EXIT_SUCCESS);
}
