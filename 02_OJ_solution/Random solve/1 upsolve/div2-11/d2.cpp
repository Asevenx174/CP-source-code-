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
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ;  
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   if(n==1)
   {
      cout << n << endl ; return 0 ; 
   }
   else if(n==3)
   {
      cout << "1 1 3" << endl ; return 0 ; 
   }
   int k = n ;
   int p = 1 ; 
   int f=0,idx=1 ; 
   while(p<=n)
   {
      int q = p*2 ; 
      int d = k-(n/q) ; 
      k-=d ;
      while(d--)
      {
         ar[idx++] = p ;  
      }
      p = q ; 
   }
   int val = n%2==1 ? n-1 : n ; 
   while(val>0)
   {
      if(val%ar[n-1]==0)
      {
         break ; 
      }
      val-=2 ; 
   }
   ar[n] = max(ar[n],val) ; 
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ar[i+1] ; 
   }
   cout << endl ;
   return 0 ;
}