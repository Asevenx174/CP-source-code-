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
int ar[maxx],n,br[maxx+10],add[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n ;
      cin >> n ;
      for(int i=1;i<=n;i++)
      {
         cin >> br[i] ; 
      } 
      add[2] = 0 ; 
      ll f = 1 ; 
      for(int i=3;i<=n;i++)
      {
         ll temp = (br[i-1]-br[i-2])-(br[i]-br[i-1]) ;
         ll dd = max(temp,-temp) ; 
         if(dd%n!=zz){f=0;break;}
         ll res = dd/n ; 
         if(temp>=0)
         {
             add[i] = add[i-1]+res ; 
         }
         else
         {
             add[i] = add[i-1]-res ; 
         }
      }
      if(f==0)
      {
         cout << "NO" << endl ; continue ; 
      }
      ll k=0,z=0,sum=0,r=0,ex=0 ; 
      for(int i=2;i<=n;i++)
      {
          k+=add[i] ; 
          z+=(n-i+2) ; 
          r+=( add[i]*(n-i+2)) ; 
      }
      sum = (2*br[1]-br[2]+k-r)*2 ;
      if(sum%( n*(n+1))!=0){f=0;}
      sum = sum/( n*(n+1) ) ;  
      ar[2] = sum ; 
      sum = 0 ; 
      for(int i=2;i<=n;i++)
      {
         sum+=( (ar[2]+add[i])*(n-i+2) ) ; 
      }
      ar[1] = br[1]-sum ; 
      if(f==0)
      {
         cout << "NO" << endl ; continue ; 
      }
      cout << "YES" << endl ; 
      for(int i=1;i<=n;i++)
      {
         if(i!=1){cout << " " ;}
         int val = i>2 ? ar[2]+add[i] : ar[i] ; 
         cout << val ; 
      }
      cout << endl ; 
   }
   return 0 ;
}