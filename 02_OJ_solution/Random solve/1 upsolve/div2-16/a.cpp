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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,br[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int a = 0 ; 
      int b = 0 ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         if(ar[i+1]==1){a++;}else{b++;}
         br[i+1] = 0 ; 
      }
      if(n%2==1)
      {
         cout << "-1" << endl ; continue ; 
      }
      int idx = 1 ; 
      int val = a > b ? 1 : -1 ; 
      int ans = n ; 
      while(a!=b && idx<=n)
      {
         if(ar[idx]!=val){ br[idx]=0 ; idx++;continue;}
         if(idx==n){break;}
         if(ar[idx+1]==val)
         {
            br[idx]=1 ; 
            br[idx+1]=1 ; 
            if(a>b){a--;b++;}else{b--;a++;}
            ans-- ; 
         }
         else
         {
            br[idx] = 0 ;
            br[idx+1] = 0 ; 
         }
         idx+=2 ; 
      }
      cout << ans << endl ;
      for(int i=1;i<=n;i++)
      {
         if(br[i]==0)
         {
            cout << i << " " << i << endl ;
         }
         else
         {
            cout << i << " " << i+1 << endl ;
            i++ ; 
         }
      }
   } 
   return 0 ;
}