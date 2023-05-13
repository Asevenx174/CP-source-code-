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
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;
ll n,m;
vector < pii > g[maxx];
bool used[maxx];
vector < ll > dis(maxx,imax);
void dijsktra()
{
    dis[1]=0;
    priority_queue < pii > pq ;
    pq.push({0,1});
    while(!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        ll u = p.ss ;
        if(used[u]){continue;}
        used[u]=true;
        for(auto it : g[u])
        {
           ll cost = it.ss , v = it.ff ;
           if(cost+dis[u]<dis[v])
           {
               dis[v]=dis[u]+cost ;
               pq.push({-dis[v],v});
           }
        }
    }
}
int main()
{
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       int u,v,w ;
       cin >> u >> v >> w ;
       g[u].push_back({v,w});
   }
   dijsktra();
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ; }
       cout << dis[i];
   }
   cout << endl;
   return 0 ;
}
