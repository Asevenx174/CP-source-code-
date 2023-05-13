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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector < int > g[maxx+10] ;
bool used[maxx+10] ; 
int sub[maxx+10],l[maxx+10],r[maxx+10] ;  
void dfs(int u)
{
   used[u] = true ; 
   int idx = 1 ; 
   for(auto v : g[u] )
   {
      if(!used[v])
      {
         if(idx==1)
         {
            l[u] = v ; 
         }
         else
         {
            r[u] = v ; 
         }
         idx++ ; 
         dfs(v) ; 
         sub[u] += ( sub[v]+1 ) ; 
      }
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ; 
   while(test--)
   {
      int n ;
      cin >> n ; 
      for (int i = 0; i < n+5 ; ++i)
      {
         g[i].clear() ; 
         used[i] = false ; 
         sub[i] = 0 ; 
         l[i] = 0  ;
         r[i] = 0 ; 
      }
      for (int i = 0; i+1 < n ; ++i)
      {
         int u,v ;
         cin >> u >> v ; 
         g[u].push_back(v) ; 
         g[v].push_back(u) ; 
      }
      dfs(1) ; 
      queue < int > q ; 
      q.push(1) ; 
      int ans = 0 ; 
      while(!q.empty())
      {
         int u = q.front() ; 
         q.pop() ; 
         int a = l[u] ; 
         int b = r[u] ; 
         if(sub[a]>sub[b])
         {
            ans+=sub[a] ; 
            if(sub[b]>0)
            {
               q.push(b) ; 
            }
         }
         else
         {
            ans+=sub[b] ; 
            if(sub[a]>0)
            {
               q.push(a) ; 
            }
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}