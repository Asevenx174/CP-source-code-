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
ll n,q,arr[maxx],t[maxx],lvl[maxx],pp,brr[maxx],pq[maxx],sub[maxx];
vector < int > g[maxx];
void update(int idx,int v)
{
    int y = v-brr[idx];
    brr[idx]=v;
    v = y ;
    while(idx<=n)
    {
        t[idx]+=v;
        idx = idx+(idx&(-idx));
    }
}
ll query(int idx)
{
    ll sum = 0 ;
    while(idx>0)
    {
        sum+=t[idx];
        idx = idx-(idx&(-idx));
    }
    return sum ;
}
void dfs(int p,int c)
{
    lvl[pp]= c ;
    pq[c]=pp;
    pp++;
    ll ans = 1 ;
    for(auto x : g[c] )
    {
        if(x!=p)
        {
            dfs(c,x);
            ans+=sub[x];
        }
    }
    sub[c]=ans;
}
int main()
{
   cin >> n >> q ;
   for(int i=1;i<=n;i++){cin >> arr[i];}
   for(int i=1;i<n;i++)
   {
       int u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   pp = 1 ;
   dfs(0,1);
   for(int i=1;i<=n;i++)
   {
       int y = arr[lvl[i]];
       update(i,y);
   }
   while(q--)
   {
       int p,s,x;
       cin >> p ;
       if(p==1)
       {
           cin >> s >> x ;
           s = pq[s] ;
           update(s,x);
       }
       else
       {
           cin >> x ;
           int y = pq[x] ;
           int l = y , r = y+sub[x]-1 ;
           ll ans = query(r)-query(l-1);
           cout << ans << endl ;
       }
   }
   return 0 ;
}
