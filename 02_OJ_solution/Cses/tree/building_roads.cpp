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
int par[maxx],siz[maxx];
void set_(int u)
{
    par[u]=u;
    siz[u]=1;
}
int find_(int u)
{
    if(u==par[u]){return u;}
    return par[u]=find_(par[u]);
}
void union_(int a,int b)
{
    a = find_(a);
    b = find_(b);
    if(a!=b)
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        par[b]=a;
        siz[a]+=siz[b];
        siz[b]=0;
    }
}
set < int > p ;
int main()
{
   int n,m ;
   cin >> n >> m ;
   for(int i=1;i<=n;i++)
   {
       set_(i);
   }
   for(int i=1;i<=m;i++)
   {
       int u,v ;
       cin >> u >> v ;
       union_(u,v);
   }
   int pre = 0 ;
   vector < pii > ans ;
   for(int i=1;i<=n;i++)
   {
       if(siz[i]!=0)
       {
           if(pre==0)
           {
               pre=i ;
           }
           else
           {
               ans.push_back({i,pre});
               pre = i ;
           }
       }
   }
   cout << ans.size() << endl;
   for(auto k : ans )
   {
       cout << k.ff << " " << k.ss << endl;
   }
   return 0 ;
}
