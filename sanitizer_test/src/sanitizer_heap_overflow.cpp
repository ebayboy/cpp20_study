#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func1(void)
{
    char *p = (char*)malloc(sizeof(char) * 4);
    char chs[] = {"12345"};
    memset(p, 0x0, 4);
    if (p != NULL)
    {
        memcpy(p, chs, 5);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    func1();
    return 0;
}
