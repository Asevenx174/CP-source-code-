#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", evaluations.in);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int prime[maxx+10];
void seive(int n)
{
    memset(prime,0,sizeof(prime));
    int x = sqrt(n);
    prime[0]=prime[1]=1;
    for(int i=4;i<=n;i+=2)
    {
        prime[i]=1;
    }
    for(int i=3;i<=x;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
std::vector < int > g[maxx+10],val[maxx+10];
int n ; 
int par[maxx+10] ; 
bool used[maxx+10] ;
ll ans = 0 ;  
ll calco(ll f)
{
   if(f<2){return 0;}
   if(f==2){return 1;}
   ll ans = f*(f-1) ; 
   ans = ans/2LL ; 
   return ans ; 
}
void dfs(int u,int gp)
{
   used[u] = true ; 
   ll f = 0 ; 
   for (int i = 0; i < g[u].size() ; ++i)
   {
      int v = g[u][i]; 
      int w = val[u][i]; 
      if(used[v]){continue;}
      if(prime[w]==0){ans++;}
      if(par[u]!=0)
      {
         if(gp!=w && prime[w]==0 && prime[gp]==0)
         {
            ans++ ; 
         }
      }
      if(prime[w]==0){f++;}
      dfs(v,w) ; 
   }
   ans+=( calco(f) ) ; 
}
int main()
{
   debugMode();
   seive(maxx) ; 
   int test,pos=1 ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < maxx ; ++i)
      {
         g[i].clear() ; 
         val[i].clear() ; 
      }
      ans = 0 ; 
      cin >> n ;
      for (int i = 0; i+1 < n ; ++i)
      {
         int x,y,w ;
         scanf("%d %d %d",&x,&y,&w) ; 
         g[x].push_back(y) ; 
         g[y].push_back(x) ;
         val[x].push_back(w) ; 
         val[y].push_back(w) ;
      }
      par[1] = 0 ; 
      par[0] = 0 ; 
      dfs(1,0) ; 
      printf("Case %d: %d\n",pos++,ans) ; 
   }
   return 0 ;
}