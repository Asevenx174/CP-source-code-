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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
      int n ;
      cin >> n ;
      string s ;
      cin >> s ;
      int idx = 1 ,co=0 ; 
      for(auto c : s )
      {
         int x = c-'0' ; 
         ar[idx++] = x ; 
         if(x==9){co++;}
      }
      if(co==n)
      {
         s[n-1] = '2' ; 
         cout << s << endl ; continue ; 
      }
      if(ar[1]==9)
      {
         cr[1] = 1 ; 
         cr[n] = 1 ; 
         cr[0] = 1 ; 
         cr[n-1] = 1 ; 
         for(int i=2;i<n-1;i++)
         {
            cr[i] = 0 ; 
         } 
         int temp = n ; 
         while(n>0)
         {
            br[n] = cr[n]-ar[n] ; 
            if(br[n]<0)
            {
               br[n]+=10 ; 
               ar[n-1]++ ; 
            }
            n-- ; 
         }
         n = temp ; 
      }
      else
      {
         for(int i=1;i<=n;i++)
         {
            br[i] = 9-ar[i] ; 
         }
      }
      for(int i=1;i<=n;i++)
      {
         cout << br[i] ; 
      }
      cout << endl ;
   }
   return 0 ;
}