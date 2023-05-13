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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m ; 
std::vector < int > g[maxx+10],dis(maxx,mod) ;

int up[maxx][35],tim=0,in[maxx],out[maxx],h,lvl[maxx+10];
void dfs(int p,int c)
{
    in[c]=tim++;
    up[c][0]=p ;
    for(int i=1;i<=h;i++)
    {
        up[c][i]=up[ up[c][i-1] ][ i-1 ] ;
    }
    for(auto x : g[c])
    {
        if(x!=p)
        {
            lvl[x] = lvl[c]+1 ; 
            dfs(c,x);
        }
    }
    out[c]=tim++;
}
bool ancestor(int a,int b)
{
    if( (in[a]<in[b]) && (in[b]<out[b]) && (out[b]<out[a]) )
    {
        return true ;
    }
    return false ;
}
int lca(int a,int b)
{
    if(a==b) {return a ; } /////************************8
    if(ancestor(a,b))
    {
        return a ;
    }
    if(ancestor(b,a))
    {
        return b ;
    }
    for(int i=h;i>=0;i--)
    {
        if(!ancestor(up[a][i],b) && up[a][i]>0)
        {
            a = up[a][i] ;
        }
    }
    return up[a][0];
}

void bfs(int x)
{
   dis[x] = 0 ;  
   queue < int > q ; 
   q.push(x) ; 
   while(!q.empty())
   {
      int u = q.front() ; q.pop() ; 
      for(auto v : g[u])
      {
         if(dis[v]>dis[u]+1)
         {
            dis[v] = dis[u]+1 ; 
            q.push(v) ; 
         }
      }
   } 
}

int calco(int a,int b)
{
   int c = lca(a,b) ; 
   int ans = lvl[a]+lvl[b]-2*lvl[c] ; 
   return ans ;  
}
void solve()
{
   vector < pii > q ; 
   cin >> n >> m ; 
   for (int i = 0; i+1 < n ; ++i)
   {
      int u,v ;
      scanf("%d %d",&u,&v) ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      int t,v ;
      scanf("%d %d",&t,&v) ; 
      q.push_back({t,v}) ; 
   }

   h = ceil(log2(n));
   lvl[1] = 1 ; 
   dfs(0,1);

   bfs(1) ;  
   int s = sqrt(m) ; 
   int idx = 0 ; 
   vector < int > pv ; 
   pv.push_back(1) ; 
   while(idx<m)
   {
      vector < int > temp ; 
      int l = idx ; 
      int r = min(idx+s-1,m-1) ;
      for (int i = l ; i <= r ; ++i)
      { 
         int t = q[i].ff ; 
         int v = q[i].ss ;  
         if(t==1)
         {
            bfs(v) ; 
            temp.push_back(v) ; 
         }
         else
         {
            int ans = dis[v] ; 
            for(auto x : pv)
            {
               ans = min(ans,calco(v,x)) ; 
            }
            printf("%d\n",ans) ;  
         }
      }
      idx = r+1 ;  
      pv.clear() ; 
      for(auto x : temp)
      {
         pv.push_back(x) ; 
      }
   }
}


int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}