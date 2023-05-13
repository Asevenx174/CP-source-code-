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
ll n,m,f[maxx+10] ; 
bool valid(ll t)
{
   ll done = 0,op=0 ; 
   for(int i=1;i<=n;i++)
   {
      ll lim = min(f[i],t) ; 
      done+=lim ; 
      op+=((t-lim)/2LL) ;
   }
   ll need = m-done ;
   if(op>=need){return true ;}
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(f,0) ; 
      cin >> n >> m ; 
      for (int i = 0; i < m ; ++i)
      {
         int x ;
         cin >> x ;
         f[x]++ ; 
      }
      int l=1,r=mod,ans=0 ; 
      while(l<=r)
      {
         int mid = (l+r)/2 ; 
         if(valid(mid))
         {
            ans = mid ; 
            r = mid-1 ; 
         }
         else
         {
            l = mid+1 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}