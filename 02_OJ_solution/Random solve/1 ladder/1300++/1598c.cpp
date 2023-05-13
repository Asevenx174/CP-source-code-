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


using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 32768+32768+10,mod= 32768,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx+10],ar[mod+10] ;
void ini()
{
    for (int i = 0; i < maxx ; ++i)
    {
        dp[i] = mod ; 
    }
} 
void calco(int x,int t)
{
   if(dp[x]<=t){return ;}
   dp[x] = t ; 
   if(x==0){return ;}
   calco( (2*x)%mod,t+1 ) ; 
   calco( (x+1)%mod,t+1 ) ;
}
int main()
{
   debugMode();
   std::vector < int > ans ;
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
       int x = ar[i+1] ; 
       ini() ; 
       int t = 0 ;
       while(x*2<=mod)
       {
         t++ ; 
         x = x*2 ; 
       }
       calco(x,t) ; 
       ans.push_back(dp[0]) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i!=0){cout << " " ; }
      cout << ans[i] ; 
   }
   cout << endl ;
   return 0 ;
}