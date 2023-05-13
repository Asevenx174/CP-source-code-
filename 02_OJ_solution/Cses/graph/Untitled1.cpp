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
const int imin = 1e9+100;
const ll maxx = 2510 ,mod=1e9+7,imax=1e18+10;
ll n,m;
vector < pii > g[maxx];
vector < bool > relaxed(maxx,false),used(maxx,false);
vector < ll > dis(maxx,imax),par(maxx,-1),cnt(maxx,0);
ll node = -1 ;
bool bellman(ll u)
{
    dis[u]=0;
    queue < int > q ;
    q.push(u);
    while(!q.empty())
    {
        ll u = q.front() ;
        q.pop() ;
        used[u]=true ;
        relaxed[u]=false ;
        for(int i=0;i<g[u].size();i++)
        {
            ll v = g[u][i].ff , w = g[u][i].ss ;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w ;
                par[v]=u;
                if(!relaxed[v])
                {
                    relaxed[v]=true ;
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v]==n){ node = v ;  return false;}
                }
            }
        }
    }
    return true ;
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

   for(int i=1;i<=n;i++)
   {
       if(!used[i])
       {
           if(!bellman(i))
           {
               cout << "YES" << endl;
               cout << node << endl;
               int idx = 0 ;
               ll temp = node ;
               vector < int > k ;
               while(1)
               {
                   k.push_back(node);
                   node = par[node] ;
                   if(node==temp){k.push_back(node);break;}
               }
               reverse(k.begin(),k.end());
               for(auto x : k)
               {
                   if(idx!=0){cout << " " ;}
                   idx = 1 ;
                   cout << x ;
               }
               cout << endl;
               return 0 ;
           }
       }
   }
   cout << "NO" << endl;
   return 0 ;
}
