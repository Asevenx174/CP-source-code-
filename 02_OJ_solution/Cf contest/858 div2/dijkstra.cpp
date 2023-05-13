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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int dis[maxx],nodes ;
vector < pii > g[maxx+10] ; 

// find shortest path from node 1 to all nodes 
void dijkstra()
{
    for(int i = 1; i <= nodes; i++)
    {
       dis[i] = mod ; 
    }
    dis[1] = 0;
    priority_queue< pii,vector<pii>,greater<pii>> q ;
    q.push({0,1});
 
    while(!q.empty())
    {
        pii p = q.top();
        q.pop();
 
        int u = p.ss, cost = p.ff;
        if(cost > dis[u]) { continue ; }
 
        for( auto pr : g[u] )
        {
            int v = pr.ff;
            int next_cost = cost + pr.ss ;
 
            if(next_cost < dis[v])
            {
                dis[v] = next_cost ;
                q.push({next_cost,v});
            }
        }
    }
}

int main()
{
   debugMode();
 
   return 0 ;
}