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
int arr[maxx],par[maxx];
bool used[maxx];
vector < int > g[maxx];
int f=0;
void dfs(int p,int c,int idx)
{
    if(f==1){return ; }
    par[c]=p;
    used[c]=true ;
    arr[c]=idx ;
    for(auto x : g[c] )
    {
        if(!used[x])
        {
            dfs(c,x,!idx);
        }
        else if (x==par[p])
        {
            f=1;
            return ;
        }
    }
}
int main()
{
   int n,m ;
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       int u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   for(int i=1;i<=n;i++)
   {
       if(!used[i])
       {
           dfs(0,i,1);
       }
   }
   if(f==1)
   {
       cout << "IMPOSSIBLE" << endl ;
       return 0 ;
   }
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       if(arr[i]==0){arr[i]=2;}
       cout << arr[i];
   }
   cout << endl;
   return 0 ;
}
