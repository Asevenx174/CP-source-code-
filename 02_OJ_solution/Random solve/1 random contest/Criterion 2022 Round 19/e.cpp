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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
            a = (a * a) % mod;
            p /= 2;
        } 
        else 
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res ;
}

ll ncr(int n, int k)
{
    if (k > n) { return 0; }
    return fact[n] * inv[k] % mod * inv[n - k] % mod;
}
void precalco()
{
   fact[0] = inv[0] = 1;
   for (int i = 1; i < maxx; i++)
   {
      fact[i] = (fact[i - 1] * i) % mod;
      inv[i] = fastpow(fact[i], mod - 2);
   }
}
int main()
{
   debugMode();
   precalco() ; 
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,m,k ;
      cin >> n >> m >> k ;
      std::vector < ll > v ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         v.push_back(x) ; 
      }
      sort(v.begin(),v.end()) ; 
      ll ans = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
         ll l = i+1 ; 
         ll r = upper_bound(v.begin(),v.end(),v[i]+k)-v.begin()+1 ;
         ll len = r-l ; 
         ll add = ncr(len-1,m-1) ;
         ans = (ans+add)%mod ; 
      }
      cout << ans << endl ; 
   }
   return 0 ;
}