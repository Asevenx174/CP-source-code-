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
#define pii                pair < long long , long long >

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
typedef int ll ;
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


ll dist( pii  p1, pii  p2)
{
   ll x0 = p1.ff - p2.ff;
   ll y0 = p1.ss - p2.ss ;
   return x0*x0 + y0*y0 ;
}


double maxDist( pii p[],int n)
{
   double Max = 0;

   for(int i = 0; i < n; i++)
   {
      for(int j = i + 1; j < n; j++)
      {
         Max = max(Max, (double)dist(p[i],p[j]));
      }
   }
   return sqrt(Max);
}

pii p[maxx+10] ; 
int main()
{

   debugMode() ; 

   int n ;
   cin >> n ;

   for (int i = 0; i < n ; ++i)
   {
      ll x,y ;
      scanf("%d %d",&x,&y) ; 
      p[i].ff = x ; 
      p[i].ss = y ;  
   }
   cout << fixed << setprecision(8) << maxDist(p, n) << endl ;
   return 0;
}

