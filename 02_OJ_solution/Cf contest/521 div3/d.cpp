#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
ll f[maxx+10],n,k,ar[maxx+10],br[maxx+10],lim ; 
vector < ll > pq ; 
bool valid(ll m,ll idx)
{
   ll sum = 0 ; 
   lp(i,1,lim)
   {
      ll x = br[i] ; 
      sum+=(x/m) ; 
      ll temp = x/m ; 
      if(idx==1)
      {
         while(temp--)
         {
            pq.push_back()
         }
      }
   }
   if(sum>=k){ return true ; }
   return false ;
}
int main()
{
   debugMode();
   cin >> n >> k ;
   lp(i,1,n)
   {
      cin >> ar[i] ; 
      f[ ar[i] ]++ ; 
   }
   std::vector< ll > v;
   lp(i,1,maxx)
   {
      if(f[i]>0)
      {
         v.push_back(f[i]) ; 
      }
   }
   sort(v.begin(),v.end(),greater<int>()) ; 
   ll idx = v.size() ; 
   lim = min(k,idx) ; 
   idx = 1 ; 
   for(auto x : v )
   {
      br[idx++]=x ; 
      if(idx>lim){break;}
   }
   ll l=0,r=n,ans=0 ; 
   while(l<=r)
   {
       ll m = (l+r)/2LL ;
       if(valid(m,0))
       {
          ans = m ; 
          l = m+1  ;
       }
       else
       {
          r = m-1 ; 
       }
   }
   cout << ans << endl ;
   return 0 ;
}