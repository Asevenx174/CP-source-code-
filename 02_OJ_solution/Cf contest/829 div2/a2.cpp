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
const ll maxx = 25 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],n,best ; 
void calco(int i,int j)
{
   for (int i = 0; i < n ; ++i)
   {
      br[i+1] = ar[i+1] ; 
   }
   int ans = 0 ; 
   if(i>0)
   {
      br[i] = __gcd(br[i],i) ; 
      ans+=(n-i+1) ; 
   }
   if(j>0)
   {
      br[j] = __gcd(br[j],j) ; 
      ans+=(n-j+1) ; 
   }
   int g = br[1] ; 
   for(int i=2;i<=n;i++)
   {
      g = __gcd(g,br[i]) ; 
   }
   if(g==1)
   {
      best = min(best,ans) ; 
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      best = mod ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for(int i=0;i<=n;i++)
      {
         calco(i,0) ; 
         for(int j=i+1;j<=n;j++)
         {
            calco(i,j) ; 
         }
      }
      cout << best << endl ;
   }
   return 0 ;
}