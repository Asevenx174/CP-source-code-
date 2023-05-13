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
ll n,k,lim; 
std::vector < ll > g[maxx+10],pq ; 
std::vector< pii > pp ;
bool valid(ll m,ll idx)
{
    ll sum = 0 ,j = 1  ; 
    for(auto p : pp)
    {
       ll i = p.ss ; 
       ll f = p.ff ; 
       ll t = f/m ; 
       sum+=t ; 
       if(idx==1)
       {
          while(t--)
          {
             pq.push_back(i) ; 
          }
       }
       j++ ; 
       if(j>lim){break;}
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
      ll x ;
      cin >> x ;
      g[x].push_back(i) ; 
   }
   ll len = 0 ; 
   lp(i,1,maxx)
   {
      if(g[i].size()==0){continue;}
      pp.push_back({g[i].size(),i}) ; 
      len++ ; 
   }
   sort(pp.begin(),pp.end(),greater<pii>()) ; 
   lim = min(k,len) ;  
   
   ll l=0,r=n,ans=0,idx=0;
   while(l<=r)
   {
      ll m = (l+r)/2LL ;
      if(valid(m,0))
      {
         ans = m ; 
         l = m+1 ; 
      }
      else
      {
         r = m-1 ; 
      }
   }
   valid(ans,1) ; 
   for(auto x : pq )
   {
      if(idx!=0){cout << " " ; }
      idx = 1 ; 
      cout << x ; 
   }
   cout << endl ;
   return 0 ;
}