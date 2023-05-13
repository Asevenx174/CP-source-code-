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
const ll maxx = 2010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx][maxx],n,br[maxx][maxx]  ;
int fx[10] = {-1,-1,1,1} ; 
int fy[10] = {-1,1,1,-1} ; 
int co(int i,int j,int idx)
{
   int temp = 0 ;
   while( max(i,j)<=n && min(i,j)>0 )
   {
      temp+=br[i][j] ; 
      i+=fx[idx];
      j+=fy[idx];
   }
   return temp ; 
}
int calco()
{
   int best = 0 ; 
   for(int i=1;i<=n;i++)
   {
      int j=1 ;  
      best = max(best,co(i,j,1)) ; 
      best = max(best,co(i,j,2)) ; 
      best = max(best,co(j,i,3)) ; 
      best = max(best,co(j,i,0)) ;

      best = max(best,co(i,n,0)) ; 
      best = max(best,co(i,n,3)) ; 
      best = max(best,co(i,n,1)) ; 
      best = max(best,co(i,n,2)) ; 
   }
   return best ; 
}
void shift(int t)
{
   for(int i=1;i<=n;i++)
   {
      int j = i-t ; 
      if(j<1)
      {
         j = n+j ; 
      }
      for(int k=1;k<=n;k++)
      {
         br[k][j] = ar[k][i] ;  
      }
   }
} 

int main()
{
   debugMode();
   int test ; 
   cin >> test ;
   while(test--)
   {
      int one = 0 ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='0' ? 0 : 1 ; 
            one+=x ; 
            ar[i+1][j+1] = x ; 
            j++ ;
         }
      }
      int d1 = 0 ; 
      for(int i=0;i<n;i++)
      {
         shift(i) ;
         d1 = max(d1,calco()); 
      }
      int ans = n-d1+one-d1 ; 
      cout << ans << endl ;
   }
   return 0 ;
}