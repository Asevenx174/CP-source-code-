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

vector < pii > g[maxx],trop;
ll used[maxx],in[maxx],out[maxx],tim=0,pos[maxx],lis[maxx],diff[maxx],dis[maxx],deg[maxx];

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
   ios::sync_with_stdio(0); cin.tie(0);
   ll test ;
   cin >> test ;
   while(test--)
   {
       trop.clear();
       ll n,m,l ;
       cin >> n >> m >> l ;
       for(int i=0;i<n;i++)
       {
           cin >> diff[i] ;
           g[i].clear();
           used[i]=false;
           deg[i]=0;
       }
       while(m--)
       {
           ll u,v,w ;
           cin >> u >> v >> w ;
           if(diff[u]>diff[v])
           {
               g[u].push_back({v,w});
               deg[v]++;
           }
           else
           {
               g[v].push_back({u,w});
               deg[u]++;
           }
       }
       for(int i=0;i<n;i++)
       {
           if(deg[i]==0)
           {
               tropsort(i);
               break;
           }
       }

       sort(trop.begin(),trop.end(),greater<pii>());
       int idx = 1 ;
       for(auto pq : trop)
       {
           lis[idx]=pq.ss ;
           pos[pq.ss]=idx;
           idx++;
       }
       while(l--)
       {
           for(int i=0;i<n;i++) { dis[i] = imax ;  }
           ll s,e ;
           cin >> s >> e ;
           if(pos[e]<pos[s])
           {
               cout << "-1" << endl;
               continue ;
           }
           dis[s]=0;
           idx = pos[s] ;
           while(idx<=n)
           {
               ll u = lis[idx];

               for(auto it = g[u].begin();it!=g[u].end();it++ )
               {
                  pii pq = *it ;
                  ll v = pq.ff , w = pq.ss ;
                  if(dis[v]>dis[u]+w)
                  {
                      dis[v]=dis[u]+w ;
                  }
               }
               idx++;
           }
           if(dis[e]==imax){dis[e]=-1;}
           cout << dis[e] << endl ;
       }
   }
   return 0 ;
}
