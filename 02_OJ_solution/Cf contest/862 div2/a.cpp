#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 55+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int used[maxx+10] ; 
int n,m,pos,t=1 ; 
std::vector < int > g[maxx+10] ;
void dfs(int u)
{
   used[u] = pos ; 
   for(auto v : g[u])
   {
      if(used[v]!=0){continue;}
      dfs(v) ; 
   }
}
int calco(int x)
{
  // cout << x << endl ;
   int co = 0 ; 
   int idx = 0 ;
   while(1)
   {
      int temp = 1 << idx ; 
      if(temp>x)
      {
         return co ; 
      }
      if((x&temp)!=0){co++;}
      idx++ ; 
   }
}
void solve()
{ 
   cin >> n >> m ;
   for (int i = 0 ; i < n+2 ; ++i)
   {
      g[i].clear() ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      int u,v ;
      cin >> u >> v ;
      g[u].push_back(v) ; 
   }
   int ans = n ; 
   for (int i = 1 ; i < (1<<n); ++i)
   {
      memset(used,0,sizeof(used)) ;
      int idx = 0 ; 
      while(1)
      {
         int temp = 1 << idx ; 
         if(temp>i){break;}
         if( (i&temp)!=0 && used[idx+1]==0)
         {
            pos = idx+1 ; 
            dfs(idx+1) ;   
         }
         idx++ ; 
      }
      int f = 0 ; 
      for (int j = 0; j < n ; ++j)
      {
         if(used[j+1]>0){f++;}
      }
      //cout << i << " " << f << endl ; 
      if(f==n)
      {
         ans = min(ans,calco(i)); 
      }
   }
   cout << "Case " << t++ << ": "  ;
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}