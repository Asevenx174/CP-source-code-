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
int n,m,lr[maxx+10],rr[maxx+10],dr[maxx+10] ;
std::vector< int > g[maxx+10],co[maxx+10];
vector < int > val(maxx+10,-1) ; 
bool used[maxx+10],f[maxx+10] ; 
bool flag = true ; 
void dfs(int u)
{
   used[u] = true ; 
   for (int i = 0; i < g[u].size() ; ++i)
   {
      int v = g[u][i] ; 
      int add = co[u][i] ; 
      int temp = val[u]+add ; 
      if(used[v])
      {
         if(val[v]!=temp){flag=false;}
         continue ; 
      } 
      val[v] = temp ; 
      dfs(v);  
   }
}
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 0; i < m ; ++i)
   {
      int l,r,d ;
      cin >> l >> r >> d ; 
      g[l].push_back(r) ;
      co[l].push_back(d) ; 
      f[l] = true ; 
      f[r] = true ; 
   }
   for(int i=1;i<=n;i++)
   {
      if(f[i] && !used[i])
      {
         val[i] = 0 ;  
         dfs(i) ;  
      }
   }
   if(flag)
   {
      cout << "Yes" << endl ; 
   }
   else
   {
      cout << "No" << endl ; 
   }
   return 0 ;
}