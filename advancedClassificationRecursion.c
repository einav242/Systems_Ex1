#include"NumClass.h"
#include<math.h>

int numberOfDigit(int x){
    int counter=0;
    while(x>=1)
    {
        x=x/10;
        counter++;
    }
    return counter;
}
int isPalindrome(int x)
{
    int n=numberOfDigit(x);
    int a=x%10;
    int b=(x/pow(10,n-1));
    if(a!=b)
    {
        return 0;
    }
        x=x-(b*pow(10,n-1));
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
        if(numberOfDigit(x)==1 || numberOfDigit(x)==0)
        {

            return 1;
        }
        return isPalindrome(x);
    
}


int isArmstrong2(int x, int l,int n){
    if(l==0 && x==0)
    {
        return 1;
    }
    int y=pow(x%10,n);
    l=l-y;
    if(l<0 || x<1)
    {
        return 0;
    }
    x=x/10;
    return isArmstrong2(x,l,n);
}


int isArmstrong(int x)
{
    int n=numberOfDigit(x);
    int ans = isArmstrong2(x,x,n);
    return ans;
}