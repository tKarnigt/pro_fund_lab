#include "stdio.h"
int main(){
  int num,dgt,sum;
  scanf("%d", &num);
  dgt=num;
  while(1){
    int sum=0;
    while(dgt!=0){
      sum+=dgt%10;
      dgt/=10;
    }
    if(sum<=9){
      printf("%d", sum);
      break;
    }
    dgt=sum;
  }
  return 0;
}
