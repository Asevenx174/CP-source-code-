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
const ll maxx = 10010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< int > par[maxx+10] ;
bool used[maxx+10] ; 
int ans = 0 ,z[maxx+10]; 
void dfs(int x)
{
   used[x] = true ; 
   ans++ ; 
   for(auto y : par[x])
   {
      if(used[y]){continue;}
      dfs(y) ; 
   }
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
         par[i].clear() ; 
         used[i] = false ; 
      }
      int n,m,l ;
      cin >> n >> m >> l ;
      for (int i = 0; i < m ; ++i)
      {
         int x,y ;
         cin >> x >> y ; 
         par[x].push_back(y) ; 
      }
      ans = 0 ; 
      for (int i = 0 ; i < l ; ++i)
      {
         int x ;
         cin >> x ; 
         z[i] = x ; 
      }
      for (int i = 0; i < l ; ++i)
      {
         int x = z[i] ; 
         if(used[x]){continue;}
         dfs(x) ; 
      }
      cout << ans << endl ;  
   }
   return 0 ;
}