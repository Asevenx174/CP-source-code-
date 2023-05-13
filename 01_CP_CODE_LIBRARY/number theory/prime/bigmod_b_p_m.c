long long bigmod(long long b,long long p,long long m);
// bigmod is func that makes 2^10 t0 2^5*2^5 and 2^9 to 2^8*2*1
#include<stdio.h>
int main()
{
    long long  b=2,p=100,m=33;
    printf("%lld\n",bigmod(b,p,m));
    return 0;
}
long long bigmod(long long b,long long p,long long m)
{
    long long temp ;
    if(p==0) // base case 2^1*2^0
    {
        return 1; // 2^0==1
    }
    if(p%2==0) //2^100 k 2^50 * 2^50 then abar 2^50 hbe 2^25 *2^25
    {
      temp=bigmod(b,p/2,m);
      return ((temp%m)*(temp%m))%m ;
    }
    else
    {
        return ((b%m)*(bigmod(b,p-1,m)%m))%m ;
    }// 2^25 k 2^24 and 2^1 alada kre tader alada mod k gun kre then abar mod
}
