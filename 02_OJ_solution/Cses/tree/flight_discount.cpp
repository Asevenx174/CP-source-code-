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
ll n,m ;
vector < pii > g[maxx];
bool used[maxx];
ll par[maxx];
vector < ll > dis(maxx,imax);
void bfs()
{
    priority_queue < pii > pq ;
    pq.push({0,1});
    dis[1]=0;
    par[1]=0;
    while(!pq.empty())
    {
        pii p = pq.top() ;
        pq.pop();
        ll u = p.ss ;
        if(used[u]){continue;}
        used[u]=true ;

        for(auto it : g[u])
        {
            ll v = it.ff ,w = it.ss ;
            if(dis[u]+w<dis[v])
            {
                par[v]=u;
                dis[v]=dis[u]+w ;
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
       ll u,v,w ;
       cin >> u >> v >> w ;
       g[u].push_back({v,w});
   }
   bfs();
   ll k = n,best=0;
   while(k!=1)
   {
       ll kk = par[k] ;
       best = max(best,dis[k]-dis[kk]);
       //cout << k << " " << kk << endl;
       k = kk ;
   }
   ll ans = dis[n]+(best>>1)-best ;
   cout << ans << endl;
   return 0 ;
}
