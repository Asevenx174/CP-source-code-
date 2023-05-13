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
const ll maxx = 5050+10,mod=998244353,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}


ll prime[1000100] ;
vector < int > v ;
void seive(int n)
{
    memset(prime,0,sizeof(prime));
    int x = sqrt(n);
    prime[0]=prime[1]=1;
    for(int i=4;i<=n;i+=2)
    {
        prime[i]=1;
    }
    for(int i=3;i<=x;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
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
ll ar[maxx+10],cr[maxx+10],br[maxx+10],xr[1000100],yr[1000100],b=0,c=0 ; 
ll dp[maxx][maxx] ; 
ll calco(ll x,ll y)
{
   if(dp[x][y]!=-1){return dp[x][y];}
   if(x>c)
   {
      if(y==zz){return qq;}else{return zz;}
   }
   ll ans = 0 ; 
   if(y>zz)
   {
      ans = (calco(x+1,y-1)*inv[cr[x]-qq])%mod ; 
   }
   ll temp = (calco(x+1,y)*inv[cr[x]])%mod ;
   ans = (ans+temp)%mod ; 
   return dp[x][y] = ans ; 
}
int main()
{
   debugMode();
   precalco() ; 
   seive(1000010) ;
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j)
      {
          dp[i][j] = -1 ; 
      }
   }
   ll n ;
   cin >> n ;
   for (int i = 0; i < 2*n ; ++i)
   {
       ll x ;
       cin >> x ; 
       if(prime[x])
       {
          xr[x]++ ; 
       }
       else
       {
          yr[x]++ ; 
       }
   }
   b=0,c=0 ; 
   for(int i=1;i<=(1e6+5);i++)
   {
      if(xr[i]!=0)
      {
        b++ ; 
        br[b] = xr[i] ; 
        //cout << b << " ? " << br[b] << endl ;
      }
      else if(yr[i]!=0)
      {
        c++ ; 
        cr[c] = yr[i] ; 
        //cout << c << " " << cr[c] << endl ;
      }
   }
   if(c<n)
   {
      cout << "0" << endl ; return 0 ; 
   }
   ll ans = (calco(1,n)*fact[n])%mod ;
   for(int i=1;i<=b;i++)
   {
      ans = (ans*inv[br[i]])%mod ; 
   } 
   cout << ans << endl ;
   return 0 ;
}