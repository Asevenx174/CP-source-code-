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
int fx[10] = {1,-1,0,0} ; 
int fy[10] = {0,0,1,-1} ; 
int main()
{
   debugMode();
   ll n,a,b ;
   cin >> n >> a >> b ; 
   std::vector< pii > v ;
   for (int i = 0; i < n ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      v.push_back({x,y}) ; 
   }
   int best = 0 ,sx,sy ; 
   for (int i = 0; i < 4 ; ++i)
   {
      int x = a+fx[i] ; 
      int y = b+fy[i] ; 
      int temp = 0 ; 
      for(auto p : v )
      {
         int c = p.ff ; 
         int d = p.ss ; 
         if(i==0)
         {
            if(c>=x){temp++;}
         } 
         else if(i==1)
         {
            if(c<=x){temp++;}
         }
         else if(i==2)
         {
            if(d>=y){temp++;}
         }
         else
         {
            if(d<=y){temp++;}
         }
      } 
      if(temp>best)
      {
         best = temp ;
         sx = x ; 
         sy = y ; 
      }
   }
   cout << best << endl ;
   cout << sx << " " << sy << endl ; 
   return 0 ;
}