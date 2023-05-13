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
const ll maxx = 500+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],cr[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector < pii > pq ;
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         cr[i+1] = ar[i+1] ; 
      }
      int a = 0 ;
      int b = 0 ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         pq.push_back({ar[i+1],br[i+1]}) ; 
         if(br[i+1]==1)
         {
            a = 1 ; 
         }
         else
         {
            b = 1 ; 
         }
      }
      sort(pq.begin(),pq.end()) ; 
      sort(cr+1,cr+n+1) ; 
      int f = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
         if(ar[i+1]==cr[i+1]){f=1;}
      }
      if(f==1)
      {
         cout << "Yes" << endl ; 
         continue ; 
      }
      else if(min(a,b)==0)
      {
         
      }
      cout << "No" << endl ;
   }
   return 0 ;
}