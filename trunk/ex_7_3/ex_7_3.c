#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("BASH_ARGC=%s\n", getenv("BASH_ARGC"));
    printf("ARGC=%s\n", getenv("ARGC"));
    printf("BASH_ARGV=%s\n", getenv("BASH_ARGV"));
    printf("ARGV=%s\n", getenv("ARGV"));

    return 0;
}
