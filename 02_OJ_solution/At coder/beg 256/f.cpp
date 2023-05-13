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
const ll maxx = 1e5+10,mod=13,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m,xr[mod+10],sr[maxx+10],pr[maxx+10] ; 
map < ll , bool > used ; 
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 1 ; i < n ; ++i)
   {
      cin >> sr[i] ; 
      pr[i] = sr[i]-pr[i-1] ;  
   }
   for(int i=1;i<=m;i++)
   {
      cin >> xr[i] ; 
      used[ xr[i] ] = true ; 
   }
   set < ll > s ;
   map < ll ,int > f ; 
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         ll a = xr[j] ; 
         ll z = a-pr[i-1] ; 
         if(i%2LL==0LL)
         {
            z = -z ; 
         }
         f[z]++ ; 
         s.insert(z) ; 
      }
   }
   ll best = 0,z=0 ; 
   for(auto x : s )
   {
      if(f[x]>best)
      {
         best = f[x] ; 
         z = x ; 
      }
   }
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll a = pr[i-1] ;
      if(i%2LL==qq)
      {
         a+=z ; 
      } 
      else
      {
         a-=z ; 
      }
      if(used[a]){ans++;}
   }
   cout << ans << endl ;
   return 0 ;
}