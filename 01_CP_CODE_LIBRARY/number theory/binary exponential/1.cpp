#include<bits\stdc++.h>
using namespace std ;
/// calculate a^n in logn comx
/// a^9 -> (a^4)*(a^4)*a -> a^2*a^2 -> a^1*a^1 -> a^0=1
long long bin(long long a,long long n)
{
    if(n==0){return 1;}
    long long res = bin(a,n/2);
    if(n%2==0){return res*res;}
    else{return res*res*a;}
}
int main()
{
    long long a,n;
    cin >> a >> n ;
    cout << bin(a,n) << endl;
    return 0;
}
