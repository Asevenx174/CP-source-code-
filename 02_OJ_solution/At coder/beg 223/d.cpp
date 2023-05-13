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

vector < pii > g[maxx] ;
ll in[maxx],out[maxx],tim=0;
vector < pii > trop ;
bool used[maxx];
void tropsort(ll u)
{
    in[u]=++tim ;
    for(auto it = g[u].begin();it!=g[u].end();it++ )
    {
        pii pq = *it ;
        ll v = pq.ff ;
        if(!used[v])
        {
            tropsort(v);
        }
    }
    out[u]=++tim ;
    trop.push_back({out[u],u});
    used[u]=true ;
}

int main()
{
   debugMode();
   
   ll n,m ;
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       ll u,v,w=1 ;
       cin >> u >> v ;
       g[u].push_back({v,w});
   }
   for(int i=1;i<=n;i++)
   {
      if(!used[i])
      {
         trop.clear() ; 
         
      }
   }
   return 0 ;
}