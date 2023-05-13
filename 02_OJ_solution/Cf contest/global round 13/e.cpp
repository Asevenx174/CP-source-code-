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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 35 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll br[maxx+5][5] ; 
ll calco(ll x,ll idx)
{
   int sum = 0 ; 
   for(ll i=0;i<maxx;i++)
   {
      ll temp = qq << i ; 
      ll y = 0 ; 
      if( (x&temp)!=zz )
      {
         y = 1 ; 
         sum++ ; 
      }
      br[i+1][idx] = y ; 
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
      ms(br,0) ; 
      ll a,b ;
      cin >> a >> b ; 
      ll fa = calco(a,1) ; 
      ll fb = calco(b,2) ;
      if(fb>fa)
      {
         cout << "NO" << endl ; continue ; 
      } 
      for(ll i=32;i>0;i--)
      {
         ll j = i ; 
         if(br[j][2]==qq)
         {
            if(br[j][1]==qq)
            {
               br[j][1] = zz ; 
            }
            else
            {
               while(br[j-1][1]==0 && j>1)
               {
                  j-- ; 
               }
               if(j==qq){continue;}
               int r = j ; 
               while(r-1>0 && br[r-1][1]==1)
               {
                  r-- ; 
                  br[r][1] = 0 ; 
               }
            }
         }
      }
      ll f = 1 ; 
      for(int i=1;i<=30;i++)
      {
         if(br[i][1]==1){f=0;}
      }
      if(f==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}