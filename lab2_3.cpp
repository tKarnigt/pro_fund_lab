#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x*2-1;j++)
        {
            if(j<=i||j>(x*2-1)-i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i = 1;i<x;i++)
    {
        for(int j=x*2-1;j>=1;j--)
        {
            if(i<=j-x||j<=x-i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}