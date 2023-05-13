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
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;

vector < pii > g[maxx];
ll col[maxx],start,endd,par[maxx];
void dfs(ll u)
{
    col[u]= 1 ;
    for(auto x : g[u])
    {
        ll v = x.ff , w = x.ss ;
        if(col[v]==0)
        {
            par[v]=u;
            dfs(v);
        }
        else if (col[v]==1)
        {
            start = v ;
            endd = u ;
            return  ;
        }
    }
    col[u]= 2 ;
    return ;
}

int main()
{
   ll n,m ;
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       ll u,v,w=0 ;
       cin >> u >> v ;
       g[u].push_back({v,w});
   }
   for(int i=1;i<=n;i++)
   {
       cout << i << " ?? " << endl ;
       for(auto y : g[i])
       {
           cout << y.ff << endl;
       }
   }

   start = -1 ;
   endd = -1 ;

   for(int i=1;i<=n;i++)
   {
       if(col[i]==0)
       {
           dfs(i);
       }
   }
   if(start==-1)
   {
       cout << "IMPOSSIBLE" << endl ;
       return 0 ;
   }



   vector < int > path ;
   int temp = 0 ;
   while(1)
   {
       cout << endd << endl;
       path.push_back(endd);
       endd = par[endd] ;
       if(endd==start)
       {
           path.push_back(endd);
           endd = par[endd];
           path.push_back(endd);
           break;
       }
       temp++;
       if(temp>10){break;}
   }
   reverse(path.begin(),path.end());
   cout << path.size() << endl ;
   int idx = 0 ;
   for(auto x : path )
   {
       if(idx!=0){cout << " " ;}
       idx = 1 ;
       cout  << x ;
   }
   cout << endl;
   return 0 ;
}
