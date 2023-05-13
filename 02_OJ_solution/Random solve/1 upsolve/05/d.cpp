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
const ll maxx = 205 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< int > g[maxx+10],dep[maxx+10],pq[maxx+5] ;
int p[maxx+10],ar[maxx+10] ; 
int as = 0 ; 
bool used[maxx+10] ; 
void dfs(int u)
{
   used[u] = true ; 
   dep[ ar[u] ].push_back(as) ; 
   as++ ; 
   for(auto v : g[u] )
   {
      if(!used[v])
      {
         dfs(v) ; 
      }
   }
}
void get()
{
      for(int i=1;i<=26;i++)
      {
         if(dep[i].size()==0){continue ; }
         int idx = dep[i].size()-2 ; 
         pq[idx+1].push_back(0) ; 
         cout << i << "->" << endl ;
         while(idx>=0)
         {
            int d = dep[i][idx+1]-dep[i][idx] ; 
            for(auto x : pq[idx+1] )
            {
               cout << x+d << endl ;
               pq[idx].push_back(x+d) ; 
            }
            idx-- ; 
         }
      }
}
void clr()
{
   for (int i = 0; i < maxx ; ++i)
   {
      dep[i].clear() ; 
      pq[i].clear() ; 
   }
}
int main()
{
   debugMode();
   char cc = 'a' ; 
   int idx = 1 ; 
   map < char , int > ci ; 
   map < int , char > ic ; 
   while(cc<='z')
   {
      ci[cc] = idx ; 
      ic[idx] = cc ; 
      idx++ ; 
      cc++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(used,false) ; 
      for (int i = 0; i < maxx ; ++i)
      {
         g[i].clear() ; 
         dep[i].clear() ; 
      }
      int n ;
      cin >> n ; 
      string s ; 
      cin >> s ;
      idx = 1 ; 
      for(auto c : s)
      {
         ar[idx++] = ci[c] ;  
      }
      for(int i=1;i<=n;i++)
      {
         cin >> p[i] ; 
         g[i].push_back(p[i]) ; 
         g[p[i]].push_back(i) ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(!used[i] && g[i].size()!=0)
         {
            clr() ; 
            dfs(i) ; 
            /*for(int j=1;j<=26;j++)
            {
               if(dep[j].size()!=0)
               {
                  cout << j << "->" <<  endl ;
                  for(auto x : dep[j])
                  {
                     cout << x << endl ;
                  }
               }
            }*/
            get() ; 
         }
      }
   }
   return 0 ;
}