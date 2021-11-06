#include "NumClass.h"
#include<math.h>

int numberOfDigit(int x){
    int counter=0;
    while(x>=1){
        x=x/10;
        counter++;
    }
    return counter;
}

int isPalindrome(int x)
{
    int n=numberOfDigit(x);
    while(n>=1)
    {
     int a=x%10;
     int c=pow(10,n-1);
     int b=(x/c);
     if(a!=b)
     {
         return 0;
     }
    x=x-(b*c);
    x=x/10;
    int k=numberOfDigit(x);
    int m=n-k;
    if(m>2)
    {
    int r=pow(10,m-2);
      if(x%r!=0)
      {
        return 0;
      }
       x=x/r;
    }
      n=numberOfDigit(x);
    }

    return 1;
}

int isArmstrong(int x)
{
    int sum=0;
    int n=numberOfDigit(x);
    int p=x;
  while (x>=1)
  {
    int a=x%10;
    int b=pow(a,n);
    sum=sum+b;
    x=x/10;
  }
  if(p==sum)
  {
      return 1;
  }
  return 0;
  
}