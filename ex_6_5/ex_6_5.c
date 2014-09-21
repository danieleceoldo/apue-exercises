#include <stdio.h>
#include <time.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    time_t t;
    struct tm *tmp;
    char c[BUFSIZ];

    if ((t = time(&t)) < (time_t) -1)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");

    if ((tmp = localtime(&t)) == NULL)
        error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__,
                "FATAL ERROR");

    strftime(c, BUFSIZ, "%a %b %d %T %Z %Y", tmp);

    printf("%s\n", c);

    exit(EXIT_SUCCESS);
}
