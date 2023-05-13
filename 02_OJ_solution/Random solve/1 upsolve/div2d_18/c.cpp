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
   int n,t ;
   cin >> n >> t ; 
   if(t==2)
   {
      while(n--)
      {
         cout << "2" ; 
      }
      cout << endl ;
   }
   else if(t==3)
   {
      int temp = n ; 
      while(temp%3!=0){temp++;}
      while(n--)
      {
         int x = 1 ; 
         if(temp>n)
         {
            int add = min(8,temp-n) ; 
            x+=add ; 
            temp-=add ; 
         }
         cout << x ; 
      }
      cout << endl ;
   }
   else if(t==4)
   {
      while(n--)
      {
         cout << "4" ; 
      }
      cout << endl ;
   }
   else if(n==5)
   {
      while(n--)
      {
         cout << "5" ; 
      }
      cout << endl ;
   }
   else if(t==6)
   {
      
   }
   return 0 ;
}