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
const ll maxx = 2e5+10 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],ans,idx ; 
void calco(ll l,ll r)
{
  ll len = r-l+1 ; 
  ll lim = (idx%2LL==1LL) ? (idx*2+1) : (idx*2) ; 
  len = len-lim+1 ;
  len = max(len,0LL) ; 
  ll add = (len*(len+1))/2LL ; 
  ans+=add ; 

}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         br[x] = i+1 ; 
      }
      ans = 1 ; 
      for(int i=0;i<n;i++)
      {
         ll x = br[i] ; 
         idx = i ; 
         if(x>1)
         {
            calco(1,x-1) ; 
         }
         if(x<n)
         {
            calco(x+1,n) ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}