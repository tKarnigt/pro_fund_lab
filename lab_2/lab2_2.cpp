#include <stdio.h>
int main()
{
    int ans;
    for(int i=1;i<=10000;i++)
    {
        ans=0;
        for(int j=1;j<=i-1;j++)
        {   
            if(i%j==0)
            {
                ans += j;
            }   
        }
        if(ans==i)
        {
            printf("%d ",ans);
        }
    }
    return 0;
}
