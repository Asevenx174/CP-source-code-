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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
vector < pii > g[maxx+10] ; 

int parent[maxx+5],sized[maxx+5];
void make_set(int v)
{
    parent[v] = v;
    sized[v]=1;
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sized[a] < sized[b])
            swap(a, b);
        parent[b] = a;
        sized[a] += sized[b];
    }
}

int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ll n,m ;
      cin >> n >> m ; 
      for (int i = 0; i <=n ; ++i)
      {
         g[i].clear() ; 
      }
      ll ans = 0 ; 
      for (int i = 0; i < m ; ++i)
      {
         ll u,v,w ; 
         cin >> u >> v >> w ; 
         g[u].push_back({v,w}) ; 
         g[v].push_back({u,w}) ; 
         ans = ans|w ; 
      }
      ll idx = 60 , sub=0 ; 
      while(idx>=0)
      {
         ll temp = qq << idx ;
         if((ans&temp)>zz)
         {
            ll mask = sub|temp ; 
            for (int i = 0; i < n ; ++i)
            {
               make_set(i+1) ; 
            }
            for(int i=1;i<=n;i++)
            {
               for(auto p : g[i] )
               {
                  int j = p.ff ; 
                  ll w = p.ss ; 
                  if(j>i && (mask&w)==zz )
                  {
                     union_sets(i,j) ; 
                  }
               }
            }
            int f = find_set(1) ; 
            if(sized[f]==n){ sub = mask ;  } 
         }
         idx-- ;  
      }
      ans-=sub ; 
      cout << ans << endl ;
   }
   return 0 ;
}