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
const ll maxx = 2510 ,mod=1e9+7,imax=1e18+10;
ll w[maxx][maxx];
vector < pii > g[maxx];
ll par[maxx],value[maxx],n,m;
vector < pii > cy ;
vector < ll > dis(maxx,-imax);
vector < ll > cnt(maxx,0);
vector < bool > used (maxx,false) ;

bool bellman()
{
   queue < int > q ;
   q.push(1) ;
   used[1]=true ;
   dis[1]=0;
   if(value[1]==5){return false;}
   while(!q.empty())
   {
       ll u = q.front() ;
       q.pop() ;
       for(auto p : g[u])
       {
           ll v = p.ff , ww = p.ss ;
           if(dis[u]+ww>dis[v] && value[v]!=5)
           {
               dis[v]=dis[u]+ww ;
               cnt[v]++;
               used[v]=true ;
               if(cnt[v]==n){return false ;}
               q.push(v);
           }
       }
   }
   return true ;
}

void dfs(int p,int c)
{
    value[c]=1 ;
    par[c]=p;
    for(auto p : g[c] )
    {
        int v = p.ff ;
        if(value[v]==0)
        {
            dfs(c,v);
        }
        else if (value[v]==1)
        {
            cy.push_back({c,v});
        }
    }
    value[c]=2;
    return ;
}



int main()
{
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       ll u,v,x ;
       cin >> u >> v >> x ;
       g[u].push_back({v,x});
       w[u][v]=x;
   }


   for(int i=1;i<=n;i++)
   {
       if(value[i]==0)
       {
           dfs(0,i);
       }
   }
   for(auto x : cy )
   {
       int c = x.ff , p = x.ss ;
       ll ans = w[c][p] ;
       vector < int > kk ;
       kk.push_back(c);
       while(c!=p)
       {
           int y = par[c] ;
           ans+=w[y][c];
           c = y ;
           kk.push_back(c);
       }
       if(ans>0)
       {
           for(auto x : kk)
           {
               value[x]=5 ;
           }
       }
   }






   if(!bellman() || dis[n]==-imax)
   {
       cout << "-1" << endl ;
   }
   else
   {
       cout << dis[n] << endl;
   }
   return 0 ;
}
