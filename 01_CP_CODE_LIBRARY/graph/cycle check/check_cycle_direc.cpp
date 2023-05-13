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
/*
  col[i]=0 not visited yet
  col[i]=1 visited but not al its children are explored yet
  col[i]=2 visited and all its children are also explored 
*/
std::vector< int > g[maxx+10] ;
int par[maxx+10],col[maxx+10],n,m ; 
int cyfirst=0,cylast=0 ; 
bool dfs(int u)
{
   col[u] = 1 ; 
   for(auto v : g[u])
   {
      if(col[v]==0)
      {
         par[v] = u ; 
         if(dfs(v))
         {
            return true ;
         }
      }
      else if(col[v]==1)// u[...]v[...]u// v has found an another route to reach u
      {
         cyfirst = v ; 
         cylast  = u ; 
         return true ; 
      }
   }
   col[u] = 2 ; 
   return false ; 
}
int main()
{
   debugMode();
   // n nodes , m edges , g graph , check cycle in O(m)
   // for undirected graph 
   int f = 1 ; 
   for (int i = 1; i <= n ; ++i)
   {
      if(col[i]==0)
      {
         if(dfs(i))
         {
            f = 0 ; 
            cout << "cycles has been found " << endl ; 
            break ; 
         }
      }
   }

   if(f==0)
   {
      cout << "IMPOSSIBLE" << endl ;
      return 0 ; 
   }
   stack < int > ans ; 
   int temp = cylast ; 
   while(temp!=cyfirst)
   {
      ans.push(temp) ; 
      temp = par[temp] ; 
   }
   ans.push(cyfirst) ; 
   ans.push(cylast) ; 
   f = 0 ;
   cout << ans.size() << endl ;
   while(!ans.empty())
   {
      if(f>0){cout << " " ; }
      f = 1 ; 
      cout << ans.top() ; 
      ans.pop() ; 
   }
   cout << endl ;

   return 0 ;
}