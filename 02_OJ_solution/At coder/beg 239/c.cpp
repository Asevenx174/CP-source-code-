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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
   int x1,x2,y1,y2 ; 
   cin >> x1 >> y1 >> x2 >> y2 ; 
   int f = 0 ; 
   for(int i=-5;i<6;i++)
   {
      for(int j=-5;j<6;j++)
      {
          int x = x1+i ; 
          int y = y1+j ; 
          int a = (x1-x)*(x1-x)+(y1-y)*(y1-y) ;  
          int b = (y2-y)*(y2-y)+(x2-x)*(x2-x) ;
          if(a==5 && b==5)
          {
             f = 1 ; 
          }
      }
   }
   if(f)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}