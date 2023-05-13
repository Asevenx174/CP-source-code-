#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,imax=2e9+10,mod=998244353,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll fact[maxx+10];
ll inv[maxx+10];

ll fastpow(ll a, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod ;
            p /= 2;
        } 
        else 
        {
            res = (res * a) % mod ;
            p--;
        }
    }
    return res ;
}

ll ncr(int n, int k)
{
    if (k > n) { return 0; }
    return fact[n] * inv[k] % mod * inv[n - k] % mod ;
}
void precalco()
{
   fact[0] = inv[0] = 1;
   for (int i = 1; i < maxx; i++)
   {
      fact[i] = (fact[i - 1] * i) % mod ;
      inv[i] = fastpow(fact[i], mod  - 2);
   }
}
ll n,m ; 
int main()
{
   debugMode() ;
   precalco() ; 
   cin >> n >> m ;
   if(n==2){cout << "0" << endl ; return 0 ;  }
   ll ans = ncr(m,n-1) ;
   ans = ( ans*ncr(n-2,1) ) %mod ;
   ans = ( ans*fastpow(2,n-3) )%mod ; 
   cout << ans << endl ;
   return 0 ;
}