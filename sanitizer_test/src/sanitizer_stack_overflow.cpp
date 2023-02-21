
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func0(void)
{
    char str[4] = {0};
    strcpy(str, "1234");
    return 0;
}

int main(int argc, char *argv[])
{
    func0();
    return 0;
}
