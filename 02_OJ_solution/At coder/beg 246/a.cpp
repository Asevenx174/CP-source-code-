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
int x[5],y[5] ; 
int a,b ; 
bool calco(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if(x2!=x3){return false ; }
    int  x4 = x1 ; 
    int y4 ; 
    if(y1==y2)
    {
      y4 = y3 ; 
    }
    else
    {
      y4 = y2 ; 
    }
    a = x4  ;
    b = y4 ; 
    return true ; 
}
int main()
{
   debugMode();
   for(int i=1;i<=3;i++)
   {
      cin >> x[i] >> y[i] ; 
   }
   for(int i=1;i<=3;i++)
   {
      for(int j=1;j<=3;j++)
      {
         for(int k=1;k<=3;k++)
         {
            if(i==j || i==k || j==k){continue;}
            calco(x[i],y[i],x[j],y[j],x[k],y[k]);
         }
      }
   }
   cout << a << " " << b << endl ;
   return 0 ;
}