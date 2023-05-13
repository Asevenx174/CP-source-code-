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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m,sr[maxx+10],xr[maxx+10],p[maxx+10] ; 
map < int , bool > pq ; 
int main()
{
   debugMode();
   cin >> n >> m ; 
   for (int i = 1 ; i < n ; ++i)
   {
      cin >> sr[i] ; 
   }
   for (int i = 1 ; i <= m ; ++i)
   {
      cin >> xr[i] ; 
      pq[ xr[i] ] = true ; 
   }
   p[1] = sr[1] ; 
   for(int i=2;i<n;i++)
   {
      p[i] = sr[i]-p[i-1] ;  
     // cout << i << " " << p[i] << endl ;
   }
   int ans = 0 ; 
   for(int i=1;i<=m;i++)
   {
      int x = xr[i] ; 
      int temp = pq[ x ] == true ? 1 : 0 ; 
      cout << " " << x ; 
      for(int j=2;j<=n;j++)
      {
         int add = (j%2)==0 ? -x : x ; 
         int y = p[j-1]+add ; 
         if(pq[y]){temp++;}
         cout << " " << y ; 
      }
      cout << endl ;
      ans = max(ans,temp) ; 
   }
   cout << ans << endl ;
   return 0 ;
}