#include"NumClass.h"
#include<math.h>

int factorial(int x)
{
    int i=1;
    int m=1;
    while(i<=x)
    {
        m=m*i;
        i++;
    }
    return m;
}

int isPrime(int x){
    int i=2;
    while(i<x)
    {
        if(x%i==0)
        {
            return 0;
        }
        i++;
    }
    return 1;

}

int isStrong(int x)
{
    int sum=0;
    int p = x ; 

   while(x>=1)
   {
       int a=x%10;
        a=factorial(a);
       sum=sum+a;
       x=x/10;
   }
   if(p==sum)
   {
       return 1;
   }
   return 0;
}