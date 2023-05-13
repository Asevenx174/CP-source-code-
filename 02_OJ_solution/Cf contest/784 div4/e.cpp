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
const ll maxx = 50 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx][maxx] ;
int main()
{
   debugMode();
   map < char ,int > pq ; 
   char c = 'a' ; 
   int idx = 1 ; 
   while(c<='k')
   {
      pq[c]=idx ;
      c++;
      idx++ ;  
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      ll ans = 0 ; 
      ms(dp,0) ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         char a = s[0] , b = s[1] ; 
         int x = pq[a] ; 
         int y = pq[b] ;
         dp[x][y]++ ;
      }
      for(int i=1;i<idx;i++)
      {
         ll sum = 0 , add=0 ; 
         for(int j=1;j<idx;j++)
         {
            sum+=dp[i][j] ; 
         }
         for(int j=1;j<idx;j++)
         {
            ll x = dp[i][j] ; 
            if(x>0)
            {
               add+=(sum-x)*x ; 
            }
         }
         add = add/2LL ; 
         ans+=add  ; 
      }
      

      for(int i=1;i<idx;i++)
      {
         ll sum = 0 , add=0 ; 
         for(int j=1;j<idx;j++)
         {
            sum+=dp[j][i] ; 
         }
         for(int j=1;j<idx;j++)
         {
            ll x = dp[j][i] ; 
            if(x>0)
            {
               add+=(sum-x)*x ; 
            }
         }
         add = add/2LL ; 
         ans+=add  ; 
      }

      cout << ans << endl ;
   }
   return 0 ;
}