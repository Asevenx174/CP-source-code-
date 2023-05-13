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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],kr[maxx+10],sum[maxx+10],best[maxx+10],n ; 
ll calco(ll val)
{
   ll l=0,r=n,ans=0 ; 
   while(l<=r)
   {
      ll m = (l+r)/2LL ; 
      if(best[m]<=val)
      {
         l = m+1 ; 
         ans = m ; 
      }
      else
      {
         r = m-1 ; 
      }
   }
   ans = sum[ans] ; 
   return ans ;  
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll q,s=0 ;
      cin >> n >> q ;
      for(int i=1;i<=n;i++)
      {
         cin >> ar[i] ; 
      }
      for (int i = 0; i < q ; ++i)
      {
         cin >> kr[i+1] ; 
      }
      for(int i=1;i<=n;i++)
      {
         s+=ar[i] ; 
         sum[i] = s ; 
         best[i] = max(best[i-1],ar[i]) ; 
      }
      for(int i=1;i<=q;i++)
      {
         if(i>1){cout << " " ; }
         ll ans = calco(kr[i]) ; 
         cout << ans ;
      }
      cout << endl ;  
   }
   return 0 ;
}