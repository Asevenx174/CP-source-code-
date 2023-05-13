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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,m ;
ll calco(ll i)
{
   ll ans = i*(n-(i+1)+1) ; 
   return ans ; 
} 
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ll ans = (n*(n+1))/2LL ; 
   for(int i=1;i<n;i++)
   {
      if(ar[i]!=ar[i+1])
      {
         ans+=calco(i) ; 
      }
   }
   while(m--)
   {
      ll idx,x ;
      cin >> idx >> x ; 
      if(ar[idx]==x)
      {
         cout << ans << endl ; continue ; 
      }
      if(ar[idx]!=ar[idx+1] && idx+1<=n)
      {
         ans-=calco(idx) ; 
      }
      if(ar[idx]!=ar[idx-1] && idx-1LL>0LL)
      {
         ans-=calco(idx-1) ; 
      }
      ar[idx] = x ; 
      if(ar[idx]!=ar[idx+1] && (idx+1)<=n)
      {
         ans+=calco(idx) ; 
      }
      if(ar[idx]!=ar[idx-1] && (idx-1LL)>0LL)
      {
         ans+=calco(idx-1) ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}