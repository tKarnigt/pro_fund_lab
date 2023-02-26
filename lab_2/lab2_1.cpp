#include <stdio.h>
#include <string.h>
int main()
{
    char x[10000];
    int sum;
    scanf("%[0-9]",&x);
    while (strlen(x) > 1) 
    {
        sum = 0;
        for (int i=0;i<strlen(x);i++) 
        {
            sum = sum + x[i] - 48;
        }
        printf("%d\n", sum);
        sprintf(x, "%d", sum);
    }
    return 0;
}
