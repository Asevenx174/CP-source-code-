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
std::vector< int > g[maxx+10] ;
bool vis[maxx+10] ; 
int co ; 
bool dfs(int u,int p)
{
   co++ ; 
   vis[u] = true ; 
   for(auto v : g[u])
   {
      if(v==p){continue;}
      if(!vis[v])
      {
         if(dfs(v,u))
         {
            return true ;
         }
      }
      else
      {
         return true ; 
      }
   }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < maxx ; ++i)
      {
         vis[i] = false ; 
         g[i].clear() ;  
      }
      set < int > s ; 
      map < pii , bool > used ;
      map < int ,int > fq ; 
      int ps = 1 ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         int a,b ;
         cin >> a >> b ; 
         fq[a]++ ; 
         fq[b]++ ; 
         if(a==b || max(fq[a],fq[b])>2){ ps=0; }
         if(a==b){continue;}
         if( used[{a,b}] || used[{b,a}] )
         {
            continue ; 
         }
         used[{a,b}]=true ;
         g[a].push_back(b) ;
         g[b].push_back(a) ;   
         s.insert(a) ; 
         s.insert(b) ; 
      }
      if(!ps){ cout << "NO" << endl ; continue ; }
      ps = 1  ; 
      for(auto x : s )
      {
         if(!vis[x])
         {
            co = 0 ; 
            if(dfs(x,-1) && co%2==1)
            {
               ps = 0 ; break ; 
            }
         }
      }
      if(!ps){cout << "NO" << endl;}
      else
      {
         cout << "YES" << endl ;
      }
   }
   return 0 ;
}