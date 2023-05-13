#include<bits\stdc++.h>
using namespace std ;
long long m=10000007;
long long bin(long long a, long long b)
{
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    long long n,k;
    while(1)
    {
        long long s=0;
        cin >> n >> k ;
        if(n==0 && k==0){return 0;}
        s=bin(n,k)%m+bin(n,n)%m+((bin(n-1,k))*2)%m+(2*(bin(n-1,n-1)))%m;
        cout << s%m << endl;
    }
    return 0;
}
