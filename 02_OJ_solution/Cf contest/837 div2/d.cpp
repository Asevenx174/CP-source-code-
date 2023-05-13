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
const ll maxx = 2e3+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx+5][maxx+5],n,ar[maxx+10],par[maxx+10],ch[maxx+10] ;
std::vector < int > g[maxx+10] ;
int ans = 0,pos=0,tr[maxx+10] ; 
vector < pii > k ; 
vector < int > temp ; 
void sett(int x,int y)
{
   //cout << x << " " << y << " --> " << dp[x][y] << endl ; 
   if(dp[x][y]!=-1){return;}
   if(x==y)
   {
      dp[y][y] = 1 ; return ;
   }
   int u = temp[ tr[x]+1 ] ; 
   int v = temp[ tr[y]-1 ] ; 
   //cout << x << " child " << u << endl ;
   //cout << y << " par " << v << endl ;
   int val = 1 ; 
   if(u==y && x==v)
   { 
      if(ar[x]==ar[y]){val=2;}
   }
   else
   {
      if(ar[x]==ar[y])
      {
         sett(u,v) ; 
         val = dp[u][v]+2 ; 
      }
      else
      {
         sett(u,y) ; 
         sett(x,v) ;  
         val = max(dp[u][y],dp[x][v]) ; 
      }
   }
   ans = max(ans,val) ; 
   dp[x][y] = val ; 
   dp[y][x] = val ; 
}

void dfs(int p,int c,int tim)
{ 
   sett(pos,c) ; 
   if(pos==1)
   {
      //cout << pos << " " << c << " " << tr[c] <<  endl ;
   }
   for(auto x : g[c])
   {
      if(x==p){continue;} 
      tr[x] = tim ; 
      temp.push_back(x) ; 
      dfs(c,x,tim+1) ; 
      temp.pop_back() ; 
      tr[x] = -1 ; 
   }
}
void solve()
{
   ans = 1 ; 
   cin >> n ;
   //cout << n << endl ;
   for (int i = 0; i < n+5 ; ++i)
   {
      for (int j = 0; j < n+5 ; ++j )
      {
         dp[i][j]=-1  ; 
      }
   }
   for (int i = 0; i < n+5 ; ++i)
   {
      g[i].clear() ; 
   }
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s)
   {
      ar[idx++] = c-'0'-48 ; 
   }
   //cout << dp[0][0] << endl ;
   for (int i = 0; i+1 < n ; ++i)
   {
      int u,v ; 
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ;  
   }
   for(int i=1;i<=n;i++)
   {
      pos = i ;  
      tr[i] = 0 ; 
      temp.push_back(i) ; 
      dfs(0,i,1) ;
      temp.pop_back() ; 
   }
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