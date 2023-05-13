#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3e5+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

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

ll n,ar[maxx+10],t,co[maxx+10] ; 
ll gen(ll idx)
{
   int temp[5] ; 
   temp[1] = ar[idx-2] ; 
   temp[2] = ar[idx-1] ; 
   temp[3] = ar[idx] ; 
   sort(temp+1,temp+4) ;
   if(temp[1]==temp[2] && temp[2]==temp[3])
   {
      return 3LL ; 
   } 
   else if(temp[1]==temp[2])
   {
      return 2LL ; 
   }
   else
   {
      return 1LL ;
   }
}
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   } 
   ll ans = ncr(n/3,n/6) ; 
   for(int i=3;i<=n;i+=3)
   {
      ll x = gen(i) ; 
      ans = (ans*x)%mod ; 
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   precalco() ; 
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}