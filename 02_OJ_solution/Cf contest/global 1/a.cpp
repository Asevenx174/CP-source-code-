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
const ll maxx = 1e5+10,mod=2 ,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
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
ll ar[maxx+10],b,k ; 
int main()
{
   debugMode();
   cin >> b >> k ;
   for (int i = 0; i < k ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ll ans = 0 ; 
   for(int i=1;i<=k;i++)
   {
      ll x = ar[i]%mod ; 
      ll y = fastpow(b,k-i) ;
      ans = (ans+(x*y)%mod)%mod ; 
   }
   if(ans==0)
   {
      cout << "even" << endl ; 
   }
   else
   {
      cout << "odd" << endl ; 
   }
   return 0 ;
}