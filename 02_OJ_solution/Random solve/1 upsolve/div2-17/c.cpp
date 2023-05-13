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
int ar[maxx+10],n,br[maxx] ; 
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
         br[i+1] = 0 ; 
         int x ;
         cin >> x ;
         ar[i+1] = x ; 
         if(x==1)
         {
           a++ ; 
         }
         else if(x==-1)
         {
           b++ ; 
         }
      }
      int sum = a+b ; 
      if(sum%2==1)
      {
         cout << "-1" << endl ; continue ; 
      }
      int val = a > b ? 1 : -1 ;
      int idx = 2  ;  
      std::vector < pii > ans ;
      
      while(a!=b && idx<=n)
      {
         if(ar[idx]!=val){idx++;continue;}
         br[idx] = 1 ; 
         br[idx-1] = 1 ; 
         idx+=2 ; 
         if(a>b){a--;b++;}else{a++;b--;}
      }
      for(int i=1;i<=n;i++)
      {
         if(br[i]==0)
         {
            ans.push_back({i,i}) ; 
         }
         else
         {
            ans.push_back({i,i+1}) ; 
            i++ ; 
         }
      }
      cout << ans.size() << endl ;
      for(auto p : ans )
      {
         cout << p.ff << " " << p.ss << endl ;
      }
   }
   return 0 ;
}