#include "stdio.h"
int main(){
  int num;
  scanf("%d", &num);
  for(int i=1;i<=num-1;i++){
    for(int j=1;j<=i;j++)printf("*");
    for(int j=1;j<=(num*2-1)-(i*2);j++)printf(" ");
    for(int j=1;j<=i;j++)printf("*");
    printf("\n");
  }

  for(int i=1;i<=2*num-1;i++)printf("*");
  printf("\n");

  for(int i=1;i<=num-1;i++){
    for(int j=1;j<=num-i;j++)printf("*");
    for(int j=1;j<=i*2-1;j++)printf(" ");
    for(int j=1;j<=num-i;j++)printf("*");
    printf("\n");
  }
  return 0;
}
