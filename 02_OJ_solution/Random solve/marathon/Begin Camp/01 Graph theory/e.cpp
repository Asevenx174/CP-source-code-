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
#define pii                pair < long long , long long  >

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e15+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m,k ; 
std::vector < pii > g[maxx+10] ;
void bfs()
{
   vector< vector < ll > > dis(n+5,vector< ll >(k+5,mod));
   priority_queue < pii , vector < pii > , greater < pii > > pq ; 
   dis[1][0] = 0 ; 
   pq.push({0,1}) ; 
   while(!pq.empty())
   {
      pii q = pq.top() ; pq.pop() ; 
      ll u = q.ss ; 
      ll d = q.ff ; 
      //cout << d << " " << u << endl ; 
      if(dis[u][k-1]<d){continue;} // no use if worsen than the worst 
      for(auto p : g[u])
      {
         ll v = p.ff ; 
         ll w = p.ss ; 
         if(dis[v][k-1]>(d+w))
         {
            dis[v][k-1] = d+w ; 
            sort(dis[v].begin(),dis[v].end()) ;
            pq.push({d+w,v}) ;  
         }
      } 
   }
   for (int i = 0; i < k ; ++i)
   {
      if(i>0){cout << " " ; }
      cout << dis[n][i] ; 
   }
   cout << endl ;
}
void solve()
{
   cin >> n >> m >> k ; 
   for (int i = 0; i < m ; ++i)
   {
      ll a,b,c ;
      cin >> a >> b >> c ; 
      g[a].push_back({b,c}) ; 
   }
   bfs() ; 
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