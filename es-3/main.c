#include <stdio.h>
#include <string.h>

int recursion(char *data)
{
    int ret = 0;

    if (strlen(data) < 1)
        return ret;

    ret = recursion(data + 1);
    printf("%c", *data);
    return ret + 1;
}

int main()
{
    int size;

    size = recursion("adcdef");
    printf(" %d\n", size);

    return 0;
}