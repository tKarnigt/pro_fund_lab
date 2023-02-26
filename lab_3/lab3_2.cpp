#include "stdio.h"
int main(){
  int sum;
  for(int i=1;i<=10000;i++){
    int sum=0;
    for(int j=1;j<=i-1;j++){
      if(i%j==0)sum+=j;
    }
    if(sum==i)printf("%d ",i);
  }
  return 0;
}
