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
const ll maxx = 1e3+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll mr[maxx+10][maxx+10],n,ar[maxx+10],br[maxx+10][maxx+10] ; 
bool valid(ll x)
{
   ar[1] = x ; 
   for(int i=2;i<=n;i++)
   {
      ar[i] = mr[1][i]/ar[1] ; 
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         if(i==j){continue;}
         br[i][j] = ar[i]*ar[j] ;
         if(mr[i][j]!=br[i][j]){return false;} 
      }
   }
   return true ; 
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < n ; ++j)
      {
         cin >> mr[i+1][j+1] ; 
      }
   }
   ll g = mr[2][1] ; 
   for(int i=3;i<=n;i++)
   {
      g = __gcd(g,mr[i][1]) ; 
   }
   for(int i=1;i*i<=g;i++)
   {
      if(g%i==0)
      {
         if(valid(i))
         {
            break ; 
         }
         ll j = g/i ; 
         if(i==j){continue;}
         if(valid(j))
         {
            break ; 
         }
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ar[i+1] ; 
   }
   cout << endl ; 
   return 0 ;
}