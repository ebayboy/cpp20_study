
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func2(void)
{
    int * a = (int*)malloc(sizeof(int) * 1);
    if ( a != NULL )
    {
        *a = 1;
        printf("a is:%d.", *a);
        free(a);
        *a = 2;
        printf("error a is:%d.", *a);
    }
}

int main(int argc, char *argv[])
{
    func2();
    return 0;
}
