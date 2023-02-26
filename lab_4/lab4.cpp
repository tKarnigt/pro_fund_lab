#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    float s = (a+b+c)/2, ans = sqrt(s*(s-a)*(s-b)*(s-c));
    if(b>a&&b>c) if(a+c<=b) printf("0"); else printf("%.2f", ans); 
    else if(a>b&&a>c) if(b+c<=a) printf("0"); else printf("%.2f", ans);
    else if(b+c<=a) printf("0");  else printf("%.2f", ans);
    return 0;
}
