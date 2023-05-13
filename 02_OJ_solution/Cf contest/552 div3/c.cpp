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
const ll maxx = 10 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[10],br[10] ; 
int s[10] ; 
ll calco(ll idx)
{
   br[1] = ar[1] ; 
   br[2] = ar[2] ; 
   br[3] = ar[3] ; 
   ll l = min(br[1]/3LL,br[2]/2LL) ; 
   l = min(l,br[3]/2LL) ; 
   br[1] = br[1]-(l*3) ; 
   br[2] = br[2]-(l*2) ; 
   br[3] = br[3]-(l*2) ; 
   ll ans = l*7LL ; 
   while(1)
   {  
      idx++ ; 
      if(idx==8){idx=1;}
      if(br[s[idx]]==0){break;}
      br[s[idx]]-- ; 
      ans++ ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   s[1]=3;
   s[2]=2;
   s[3]=1;
   s[4]=1;
   s[5]=2;
   s[6]=3;
   s[7]=1;
   cin >> ar[1] >> ar[2] >> ar[3] ; 
   ll ans = 0 ; 
   for(int i=1;i<8;i++)
   {
      ll temp = calco(i);
      ans = max(ans,temp) ; 
   }
   cout << ans << endl ;
   return 0 ;
}