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
const ll maxx = 210 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,xr[maxx+10],yr[maxx+10],pr[maxx+10],best=0,root ; 
bool vis[maxx+10] ; 
bool valid(ll s)
{
   root = 1 ; 
   while(root<=n)
   {

   ms(vis,false) ; 
   vis[root] = true ; 
   queue < ll > q ; 
   q.push(root) ; 
   ll co = 1 ; 
   while(!q.empty())
   {
      int u = q.front() ; 
      q.pop() ;
      for(int i=1;i<=n;i++)
      {
         if( !vis[i] && (pr[u]*s) >= ( abs(xr[u]-xr[i])+abs(yr[u]-yr[i]) ) )
         {
            vis[i] = true ; 
            q.push(i) ; 
            co++ ; 
         }
      }
   }
   if(co==n){return true ; }
   root++ ; 
   }
   return false ; 
   
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> xr[i+1] >> yr[i+1] >> pr[i+1] ;  
   }
   ll l=0,r=1e18+4,ans=0 ; 
   while(l<=r)
   {
      ll mid = (l+r)/2LL ;
      if(valid(mid))
      {
         ans = mid ; 
         r = mid-1 ; 
      }
      else
      {
         l = mid+1 ; 
      }
   }
   if(valid(0))
   {
      ans = 0 ; 
   }
   cout << ans << endl ;
   return 0 ;
}