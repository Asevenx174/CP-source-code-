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
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10;
vector < int > g[maxx];
int sub[maxx],lvl[maxx],best=-1,node;
int dis[maxx][5];
bool used[maxx][5];
void dfs(int p,int c)
{
    for(auto x : g[c] )
    {
        if(x!=p)
        {
            lvl[x]=lvl[c]+1 ;
            dfs(c,x);
        }
    }
    if(lvl[c]>best)
    {
        best = lvl[c] ;
        node = c ;
    }
}
void bfs(int s,int idx)
{
    dis[s][idx]=0;
    queue < int > q ;
    q.push(s);
    used[s][idx]=true ;
    while(!q.empty())
    {
        int u = q.front() ;
        q.pop();
        for(auto x : g[u])
        {
            if(!used[x][idx])
            {
                used[x][idx]=true ;
                dis[x][idx]=dis[u][idx]+1;
                q.push(x);
            }
        }
    }
    return ;
}
int main()
{
   ll n,s,e;
   cin >> n ;
   for(int i=2;i<=n;i++)
   {
       ll u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   lvl[1]=0;
   dfs(0,1);
   s = node ;
   lvl[node]=0;
   best = -1 ;
   dfs(0,node);
   e = node ;
   bfs(s,1);
   bfs(e,2);
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       cout << max(dis[i][1],dis[i][2]);
   }
   cout << endl;
   return 0 ;
}
