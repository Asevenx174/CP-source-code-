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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int xrr[maxx],sub[maxx][25]; 
std::vector< int > g[maxx] ;
vector < int > s[maxx] ; 
void dfs(int p,int c)
{
   for(auto x : g[c])
   {
      if(x==p){continue;}
      dfs(c,x);
      for(auto y : s[x])
      {
         s[c].push_back(y) ; 
      }
   }
   s[c].push_back(c) ; 
   sort(s[c].begin(),s[c].end(),greater<int>()) ;
   int temp = min(20,(int)s[c].size());
   int idx =  1 ; 
   for(auto x : s[c])
   {
      sub[c][idx++]=x ; 
      if(idx>temp){break;}
   }
   s[c].clear() ; 
   for(int i=1;i<idx;i++)
   {
      s[c].push_back(sub[c][i]) ; 
   }
}
int main()
{
   debugMode();
   int n,q ;
   cin >> n >> q ;
   for(int i=1;i<=n;i++){ cin >> xrr[i] ; }
   for(int i=1;i<n;i++)
   {
      int x,y ;
      cin >> x >> y ; 
      g[x].push_back(y) ; 
      g[y].push_back(x) ; 
   }
   dfs(0,1) ; 
   while(q--)
   {
      int x,y ;
      cin >> x >> y ; 
      cout << sub[x][y] << endl ;
   }
   return 0 ;
}