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
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< ll > v ;
      ll n, last=0 ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         ar[i+1] = x ; 
         if(x!=0)
         {
            last = i+1 ; 
         }
      }
      if(last==0)
      {
         cout << "Yes" << endl ; continue ; 
      }
      ll sum = 0 ,f=1  ; 
      while(last>0)
      {
         sum+=ar[last] ; 
         if(sum>0){f=0;}
         else if(sum==0 && last!=1)
         {
            f=0 ; 
         }
         last-- ; 
      }
      if(f==1 && sum==0)
      {
         cout << "Yes" << endl ;
      }
      else
      {
         cout << "No" << endl ;
      }
   }
   return 0 ;
}