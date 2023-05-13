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
#define pii                pair < long long , long long >

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

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

ll dis[maxx],nodes,edges ;
vector < pii > g[maxx+10] ; 
bool used[maxx+10] ; 


map < pii , int > saved ; 
vector < int > ans ; 
void dfs(int u)
{
   used[u] = true ; 
   for(auto p : g[u])
   {
      int v = p.ff , w = p.ss ; 
      if(dis[u]+w==dis[v] && !used[v])
      {
         ans.push_back(saved[{u,v}]) ; 
         dfs(v) ; 
      }
   }
}
void dijkstra()
{
    
    priority_queue< pii,vector<pii>,greater<pii>> q ;
    q.push({0,1});
    
    while(!q.empty())
    {
        pii p = q.top();
        q.pop();
        
        ll u = p.ss, cost = p.ff;
        if(used[u]){continue;}
        used[u] = true ; 
        dis[u] = cost ; 
       
        for( auto pr : g[u] )
        {
            ll v = pr.ff ;
            ll next_cost = cost+pr.ss ;
            q.push({next_cost,v});
        }
    }
}


int main()
{
   debugMode();
   cin >> nodes >> edges ; 
   for (int i = 0; i < edges ; ++i)
   {
      int u,v,w ;
      cin >> u >> v >> w ; 
      g[u].push_back({v,w}) ; 
      g[v].push_back({u,w}) ; 
      saved[{u,v}]=i+1 ; 
      saved[{v,u}]=i+1 ; 
   }
   dijkstra() ; 
   ms(used,false) ; 
   dfs(1) ; 
   int gap = 0 ; 
   for(auto x : ans )
   {
      if(gap==1){cout << " " ; }
      gap = 1 ; 
      cout << x ; 
   }
   cout << endl ;
   return 0 ;
}