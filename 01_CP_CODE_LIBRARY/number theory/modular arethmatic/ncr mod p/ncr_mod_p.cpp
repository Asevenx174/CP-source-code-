#include<iostream>
using namespace std ;
typedef long long ll ;
const ll maxx = 1e5+5,mod=1e9+7 ;
ll fact[maxx];
ll power(ll b,ll p,ll m)
{
    if(p==0){return 1;}
    ll half = power(b,p/2,m);
    ll ans,full=(half*half)%m;
    if(p%2==0)
    {
        return full;
    }
    else { return  (full*b)%m ;}
}
ll mulv(ll b,ll p)
{
    // since p is prime ;
    // b*x=1 mod p , p is prime so gcd(p,b)=1
    ll x  = power(b,p-2,p);
    return x ;
}
ll ncr(ll n,ll r)
{
    ll a,b,c;
    a = fact[n];
    b = mulv(fact[n-r],mod);
    c = mulv(fact[r],mod);
    ll ans = (a*b)%mod;
    ans = (ans*c)%mod;
    return ans ;
}
int main()
{
    ll n , k ;
    cin >> n >> k ;

    fact[0]=1;
    for(int i=1;i<=n;i++){fact[i]=(fact[i-1]*i)%mod;}

    ll ans = ncr(n,k);

    cout << ans << endl;
    return 0 ;
}
