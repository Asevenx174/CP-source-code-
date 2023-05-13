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
bool used[maxx+10],mark[maxx+10],rt[maxx+10] ; 
std::vector< int > g[maxx+10],k[maxx+10] ;
ll p[maxx+10],s,d,lvl[maxx+10],ans=0 ; 
bool dfs(ll u)
{
   used[u] = true ; 
   bool f = mark[u] ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      if(dfs(v))
      {
         f = true ; 
         p[v]=u ; 
      }
   }
   return f ; 
}
ll bfs(int u)
{
   used[u]=true ; 
   ll sum=0,add=0;
   for(auto v : k[u] )
   { 
      if(used[v]){continue;}
      ll dep = bfs(v)+1 ;
      if(rt[u] && !rt[v])
      {
          ans+=(dep*2LL) ;
      }
      sum+=dep ; 
   }
   if(u==1 && k[u].size()==1)
   {
      return 0 ; 
   }
   return sum ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,k ;
      cin >> n >> k ;
      lp(i,0,n)
      {
         used[i]=false ; 
         mark[i]=false ;
         p[i]=-1;
         rt[i]=false ;
         g[i].clear() ; 
      }
      cin >> s >> d ; 
      mark[s]=true ; 
      mark[d]=true ; 
      lp(i,1,k)
      {
         ll x ; cin >> x ; mark[x]=true ;
      }
      lp(i,2,n)
      {
         ll x,y ;
         cin >> x >> y ; 
         g[x].push_back(y) ; 
         g[y].push_back(x) ; 
      }
      bool temp = dfs(s) ;
      p[s]=s ; 
      ll x = s ; 
      rt[x]=true ; 
      ans = 1 ; 
      do
      {
         ans++ ; 
         x = p[x] ; 
         rt[x]=true ; 
      }
      while(x!=p[x]);
      lp(i,1,n)
      {
         if(p[i]!=-1 && i!=s )
         {
            k[i].push_back(p[i]) ;
            k[p[i]].push_back(i) ; 
         }
      }
      ms(used,false);
      bfs(s);
   }
   return 0 ;
}