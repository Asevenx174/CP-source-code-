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
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;
int main()
{
   vector < int > a,b ;
   int n ;
   cin >> n ;
   int x = n%4 ;
   if(x==0 || x==3)
   {
       cout << "YES" << endl;
   }
   else
   {
       cout << "NO" << endl;
       return 0 ;
   }
   if(x==0)
   {
       int i=1;
       while(i+3<=n)
       {
           a.push_back(i);
           a.push_back(i+3);
           b.push_back(i+1);
           b.push_back(i+2);
           i+=4 ;
       }
   }
   else
   {
       int i=2;
       while(i+3<=n)
       {
           a.push_back(i);
           a.push_back(i+3);
           b.push_back(i+1);
           b.push_back(i+2);
           i+=4 ;
       }
       a.push_back(i);
       a.push_back(1);
       b.push_back(i+1);
   }
   cout << a.size() << endl ;
   int idx = 0 ;
   for(auto x : a )
   {
       if(idx!=0){cout << " " ;}
       idx = 1 ;
       cout << x ;
   }
   cout << endl;

   cout << b.size() << endl ;
   idx = 0 ;
   for(auto x : b )
   {
       if(idx!=0){cout << " " ;}
       idx = 1 ;
       cout << x ;
   }
   cout << endl;

   return 0 ;
}
