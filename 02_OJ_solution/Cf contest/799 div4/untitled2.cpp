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
map < int , bool > used ;  
int ar[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   int temp = 1 , idx = 1  ; 
   while(temp<maxx)
   {
      used[temp] = true ; 
      temp = temp*2LL ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
   int n ;
   cin >> n ;
   temp = n ; 
   if(n==1)
   {
      cout << "1" << endl ;
      cout << "1" << endl ;
      continue ; 
   }
   if(n%2==1)
   {
      cout << "-1" << endl ; continue  ; 
   }
   queue < int > p ; 
   stack < int > q ; 
   while(n>0)
   {
      int len = 0 ; 
      while(1)
      {
         q.push(n) ; 
         n-- ; 
         len++ ; 
         if(used[n+1]){break;}
      }
      while(len--)
      {
         p.push(n) ; 
         n-- ; 
      } 
      len = p.size() ; 
      while(len--)
      { 
         ar[idx] = p.front() ; 
         br[idx] = q.top() ; 
         p.pop() ; 
         q.pop() ; 
         idx++ ; 
      }
   }
   n = temp/2 ; 
   int flag = 1 ; 
   for(int i=1;i<=n;i++)
   {
      if(i>1){cout << " " ; }
      cout << ar[i] << " " << br[i] ;
   }
   cout << endl ;
   for(int i=1;i<=n;i++)
   {
      if(i>1){cout << " " ; }
      cout << br[i] << " " << ar[i] ;
   }
   cout << endl ;
   }
      return 0 ;
}