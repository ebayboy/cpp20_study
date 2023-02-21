
#include <stdio.h>

int g_abc[11];

int func3(void)
{
    int i = 0;
    for (i = 0; i <= 100; i++)
    {
        printf("value:%d\t", g_abc[i]);
        if (i % 10 == 0 && i != 0)
        {
            printf("\n");
        }
    }

    return g_abc[12];
}

int main()
{
    func3();
    return 0;
}
