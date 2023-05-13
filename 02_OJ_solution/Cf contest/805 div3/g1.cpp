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
int ar[maxx+10],n ; 
std::vector < int > g[maxx+10] ;
bool mark[maxx+10],used[maxx+10] ; 
int flag ;
int dfs(int u,int co)
{
   used[u] = true ; 
   int f = 0 , k = mark[u]==true ? 1 : 0   ;
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      f+=dfs(v,max(co,k)) ; 
   }
   if(co+f>2){flag=0;}
   k = max(k,f) ; 
   return k ; 
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i+1 < n ; ++i)
   {
      int a,b ;
      cin >> a >> b ; 
      g[a].push_back(b) ; 
      g[b].push_back(a) ; 
   }
   int q ;
   cin >> q ;
   for (int i = 0; i < q ; ++i)
   {
      flag = 1 ; 
      ms(used,false) ; 
      ms(mark,false) ;   
      int k ;
      cin >> k ;
      for (int j = 0; j < k ; ++j )
      {
         int x ;
         cin >> x ;
         mark[x] = true ; 
      }
      int temp = dfs(1,0) ; 
      if(flag)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}