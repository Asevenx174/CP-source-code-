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
const ll maxx = 210 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[10]={-1,-1,1,1} ; 
int fy[10]={1,-1,-1,1} ;
int ar[maxx][maxx],r,c ; 
int calco(int i,int j)
{
   int sum = ar[i][j] ; 
   int mul = 1 ; 
   while(1)
   {
      int miss = 0 ; 
      //cout << i << " ?? " << j << endl ;
      for (int k = 0; k < 4 ; ++k)
      {
         int x = i+fx[k]*mul ; 
         int y = j+fy[k]*mul ; 
         if( (1<=x && x<=r) && (1<=y && y<=c) )
         {
             //cout << x << " " << y << endl ;
             sum+=ar[x][y] ; 
         }
         else
         {
            miss++ ; 
         }
      }
      if(miss==4){break;}
      mul++ ; 
   }
   return sum ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> r >> c ; 
      lp(i,1,r)
      {
         lp(j,1,c)
         {
            cin >> ar[i][j] ; 
         }
      }
      int ans = 0 ; 
      lp(i,1,r)
      {
         lp(j,1,c)
         {
            int temp = calco(i,j) ; 
            ans = max(ans,temp) ;  
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}