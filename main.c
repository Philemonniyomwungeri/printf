#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %c, %s, %%\n", 'W', "world");
    printf("Length: %d\n", len);

    return (0);
}

