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
   ll test ;
   cin >> test ;
   while(test--)
   {
      int W,H ;
      cin >> W >> H ; 
      int x1,x2,y1,y2 ; 
      cin >> x1 >> y1 >> x2 >> y2 ; 
      int w,h ;
      cin >> w >> h ; 
      int w2 = W-x2 ; 
      int w1 = x1 ; 
      int h1 = H-y2 ;
      int h2 = y1 ;
      
      cout << w1+w2 << " " << w << endl ; 
      cout << h1+h2 << " " << h << endl ;

      if((w1+w2)<w || (h1+h2)<h)
      {
         cout << "-1" << endl ; 
         continue ; 
      }


      int a = mod , b = mod  ; 

      if(w2-w>=0)
      {
         a = w2-w ;  
      } 
      if((w1-w)>=0 && (w1-w)<a)
      {
         a = w1-w ;  
      } 

      if(h2-h>=0)
      {
         b = h2-h ;  
      } 
      if((h1-h)>=0 && (h1-h)<b)
      {
         b = h1-h ;  
      } 
      int temp = a*a+b*b ; 
      ld  ans = (ld)temp ;
      ans = sqrt(ans) ; 
      printf("%.5Lf\n",ans) ;  
   }
   return 0 ;
}