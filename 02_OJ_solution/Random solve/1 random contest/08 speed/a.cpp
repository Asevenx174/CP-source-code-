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
const ll maxx = 10+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx],br[maxx+10][5],ex[maxx+10][5] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      memset(br,0,sizeof(br)) ; 
      memset(ex,0,sizeof(ex)) ; 
      string s ;
      cin >> s ;
      int n = s.size() ; 
      int idx = 1 ; 
      for(auto c : s )
      {
         int x ; 
         if(c=='0')
         {
            x = 0 ; 
         }
         else if(c=='1')
         {
            x = 1 ; 
            br[idx][idx%2]++ ; 
         }
         else
         {
            x = 2 ; 
            ex[idx][idx%2]++ ; 
         }
         ar[idx] = x ;
         br[idx][idx%2] = br[idx][idx%2]+br[idx-1][idx%2]  ;
         ex[idx][idx%2] = ex[idx][idx%2]+ex[idx-1][idx%2]  ;
         idx++ ;  
      }
      idx = 1 ; 
      int ans = n ; 
      while(idx<=n)
      {
         int ea = ex[idx][1] ; 
         int eb = ex[idx][0] ; 
         int la = (idx+1)/2 ; // odd
         int lb = idx-la ; 
         int rb = (n/2)-(idx/2) ; 
         int ra = (n-idx)-rb ; // odd
         int x = br[idx][0] ; 
         int y = br[idx][1] ; // odd
         if(y+eb>rb || x+ea>ra)
         {
            ans = idx ; break ; 
         }
         idx++ ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}