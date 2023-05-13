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
int ar[maxx+10],n,k ; 
std::vector< int > g[maxx+10] ;
std::vector< int > v,idx ; 
bool used[maxx+10] ; 
void dfs(int u)
{
   used[u] = true ; 
   v.push_back(ar[u]) ; 
   idx.push_back(u) ; 
   for(auto x : g[u] )
   {
      if(used[x]){continue;}
      dfs(x) ; 
   }
}
int main()
{
   debugMode();
   cin >> n >> k ;
   for(int i=1;i<=n;i++)
   {
      cin >> ar[i] ; 
   }
   for(int i=1;i<=n-k;i++)
   {
      int j = i+k ; 
      g[i].push_back(j) ; 
      g[j].push_back(i) ; 
   }
   
   for(int i=1;i<=(n-k);i++)
   {
      if(!used[i])
      {
         v.clear() ; 
         idx.clear() ; 
         dfs(i) ; 
         sort(idx.begin(),idx.end()) ; 
         sort(v.begin(),v.end()) ;
         auto it = idx.begin() ; 
         auto val = v.begin() ; 
         int temp = v.size() ; 
         while(temp--)
         {
           // cout << *it << " " << *val << endl ;
            ar[*it]=*val ; 
            it++ ; 
            val++ ; 
         } 
      }
   }
   int f = 1 ; 
   for(int i=2;i<=n;i++)
   {
      if(ar[i-1]>ar[i]){f=0;}
   }

   if(f==1)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}