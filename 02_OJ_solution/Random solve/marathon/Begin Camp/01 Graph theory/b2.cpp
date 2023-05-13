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
#define pi                pair <int,int>
#define pii               pair < pair < int ,int > ,int  >

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3000+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m,k,dis[maxx+5][maxx+5],par[maxx+10],ans=0 ; 
map < pi ,int > pq ; 
set < pii > s ;
std::vector < int > g[maxx+10],res ;
void getpath(int u,int cost)
{
   if(u==1){return;}
   for(int i=1;i<=n;i++)
   {
      if(i==u){continue;}
      if(dis[i][u]==cost)
      {
         res.push_back(i) ;
         getpath(i,cost-1) ; 
         break; 
      }
   }
}
void solve()
{
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j)
      {
         dis[i][j] = mod ; 
      }
   }
   dis[0][1] = 0 ; 
   dis[1][1] = 0 ; 
   cin >> n >> m >> k ;
   for (int i = 0; i < m ; ++i)
   {
      int u,v ;
      cin >> u >> v ; 
      g[u].push_back(v) ;
      g[v].push_back(u) ;  
   }
   for (int i = 0; i < k ; ++i)
   {
      int a,b,c ; 
      cin >> a >> b >> c ; 
      s.insert({{a,b},c}) ;
   }
   queue < pi > q ; 
   for(auto x : g[1])
   {
      q.push({1,x}) ; 
      dis[1][x] = 1 ; 
   }
   while(!q.empty())
   {
      pi temp = q.front() ; q.pop() ; 
      int gp = temp.ff ; 
      int p = temp.ss ;
      for(auto c : g[p])
      {
         auto it = s.find({{gp,p},c}) ; 
         if( it==s.end() && (dis[gp][p]+1)<dis[p][c] )
         {
            dis[p][c] = dis[gp][p]+1 ; 
            q.push({p,c}) ; 
            //cout << gp << " " << p << " " << c << " " << pq[{gp,p}] << endl ;
         }
      } 
   }
   ans = mod ; 
   for(int i=1;i<n;i++)
   {
      ans = min(ans,dis[i][n]) ; 
   }
   if(ans==mod){cout << "-1" << endl ; return ;}
   cout << ans << endl ;
   res.push_back(n) ; 
   getpath(n,ans) ; 
   reverse(res.begin(),res.end()) ; 
   for (int i = 0; i < res.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << res[i] ; 
   }
   cout << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}