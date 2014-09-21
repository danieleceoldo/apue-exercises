#include <stdio.h>
#include <stdlib.h>


typedef void Exitfunc(void);
#undef atexit
int atexit(Exitfunc *function);

void myexit(void)
{
    printf("atexit: myexit\n");
}

int main(void)
{
    if (atexit(myexit) != 0)
        exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);
}
