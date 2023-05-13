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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ll f=0,k=0 ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         if(min(ar[i],ar[i+1])>0){f=1;}
      }
      if(f==1){cout << "NO" << endl ; continue ; }
      int i=1 ; 
      while(i<=n)
      {
         if(ar[i]>0)
         {
            br[++k]=ar[i] ; 
         }
         else
         {
            ll sum = ar[i] ;
            while(i+1<=n && ar[i+1]<=0)
            {
               i++ ; 
               sum+=ar[i] ; 
            } 
            br[++k]=sum ; 
         }
         i++ ; 
      }
      for(int i=1;i<=k;i++)
      {  
         int a = i-1 ;
         int b = i ; 
         int c = i+1 ;  
         if( i==1 || i==k )
         {
            if(k<3){continue;}
            if(i==1)
            {
              a = 1 ; b = 2 ; c = 3 ; 
            } 
            else
            {
              a = k-2 ; b = k-1 ; c = k ; 
            }
         }
         ll sum = br[a]+br[b]+br[c] ; 
         ll best = max(br[a],br[b]) ;
         best = max(best,br[c]);
         if(sum>best){f=1;}
      }
      if(f==0)
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