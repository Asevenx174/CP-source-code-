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
ll ar[maxx+10],n,pr[maxx+10] ; 
ll nc2(ll n)
{
   if(n<2){return 0;}
   ll ans = n*(n-1) ; 
   ans = ans/2LL ;
   return ans ; 
}
ll nc3(ll n)
{
   if(n<3){return 0;}
   ll ans = n*(n-1)*(n-2) ; 
   ans = ans/6LL ;
   return ans ; 
}
int main()
{
   debugMode();
   cin >> n ; 
   ll sum = 0 ,ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      ll a ;
      cin >> a ;
      ans+=(a/3LL) ; 
      a = a%3LL ; 
      ar[i+1] = a ; 
   }
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==1)
      {
         sum++ ; 
      }
      else if(ar[i]==2)
      {
         if(sum>0)
         {
            sum-- ; 
            ans++ ; 
         }
         else{sum+=ar[i];}
      }
   }
   cout << ans << endl ;
   return 0 ;
}