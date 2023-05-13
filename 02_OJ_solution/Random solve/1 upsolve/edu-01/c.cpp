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
int ar[maxx+10],br[maxx+10],cr[maxx+10],dr[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      vector < int > s ;  
      std::vector < pii > pq ;
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         //pq.push_back({ ar[i+1] , i+1 }) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         s.push_back(br[i+1]) ;  
      }
      sort(pq.begin(),pq.end()) ; 
      sort(ar+1,ar+n+1) ; 
      sort(br+1,br+n+1) ; 
      int b = n-1 ; 
      for( auto p : pq )
      {
         int val = p.ff ;
         int idx = p.ss ;
         auto it = lower_bound(s.begin(),s.end(),val) ; 
         cr[idx] = (*it-val) ;
         int big = s.end()-it ; 
         cout << big << " " << b << endl ;
         b-- ; 
      }
      for(int i=1;i<=n;i++)
      {
         int in = n-i ; 
         int val = ar[i+1] ;  
      }
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ;}
         cout << cr[i+1] ; 
      }
      cout << endl ;
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ;}
         cout << dr[i+1] ; 
      }
      cout << endl ;
   }
   return 0 ;
}