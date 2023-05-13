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
const ll maxx = 200+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int br[maxx+10],n,ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      set < int > s,k ; 
      cin >> n ;
      for(int i=1;i<=2*n;i++)
      {
         k.insert(i) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         //s.insert(br[i+1]) ; 
         k.erase(k.find(br[i+1])) ; 
      }
      int f = 1,idx=1 ; 
      for(int i=1;i<=2*n;i+=2)
      {
         int x = br[idx++] ; 
         auto it = k.upper_bound(x) ; 
         if(it==k.end()){f=0;break;}
         int y = *it ; 
         ar[i] = x ; 
         ar[i+1] = y ;
         k.erase(it) ; 
      }
      if(f==0)
      {
         cout << "-1" << endl ; continue ;
      }
      for (int i = 0; i < 2*n ; ++i)
      {
         if(i>0){cout << " " ; }
         cout << ar[i+1] ;  
      }
      cout << endl ; 
   }
   return 0 ;
}