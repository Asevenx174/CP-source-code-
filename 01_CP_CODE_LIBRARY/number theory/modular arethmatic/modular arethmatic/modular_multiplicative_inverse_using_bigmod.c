// (a/b)%m=????
//(a/b)%m=((a%m)*(x%m))%m
// x = ??? x=b^(p-2)%m
// p=??
// p=1000000007 (big prime number)
// p%b==1
long long  bmod(long long b,long long p, long long m);
#include<stdio.h>
int main()
{
    // our job is find the value of x
    //// x = ??? x=b^(p-2)%m
    //  p%b==1
    // p is a prime number
    long long b=8,p=1000000007,m=34;
    printf("%lld\n",bmod(b,p,m));
    return 0;
}
long long  bmod(long long b,long long p, long long m)
{
    long long x ;
    if(p==0)
    {
        return 1;
    }
    if(p%2==0)
    {
        x=bmod(b,p/2,m);
        return ((x%m)*(x%m))%m ;
    }
    else
    {
        return ((b%m)*(bmod(b,p-1,m)%m))%m ;
    }
}

