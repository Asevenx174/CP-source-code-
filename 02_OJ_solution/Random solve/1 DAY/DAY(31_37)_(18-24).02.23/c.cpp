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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
map < int ,int > l,r ; 
int xr[maxx+10],yr[maxx+10] ; 
long long fastpow(long long a, long long b)
{
    long long res = 1;
    while (b!=zz)
    {
        if (b%tt==qq)
           {
               res = (res*a)%mod ;
           }
        a = (a*a)%mod ;
        b/=tt;
    }
    return res;
}
void solve()
{
   l.clear() ; 
   r.clear() ; 
   int n,m,k,q ;
   cin >> n >> m >> k >> q ;
   for (int i = 0; i < q ; ++i)
   {
      cin >> xr[i+1] >> yr[i+1] ; 
   }
   ll ans = 0 ; 
   for(int i=q;i>0;i--)
   {
      int x = xr[i] ; 
      int y = yr[i] ; 
      if( (l[x]==0 && r.size()<m) || (r[y]==0 && l.size()<n)  )
      { 
         ans++ ; 
      }
      l[x] = 1 ; 
      r[y] = 1 ; 
   }
   ans = fastpow(k,ans) ; 
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}