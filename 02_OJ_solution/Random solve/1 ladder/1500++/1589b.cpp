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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int calco(int n,int m,int k)
{
   if(min(n,m)==0){return k;}
   if(max(n,m)==1){return mod ; }
   if(n%3==0)
   {
      int x = n/3 ; 
      x = x*m ; 
      return x+k ; 
   } 
   if(m%3==0)
   {
      int x = m/3 ; 
      x = x*n ; 
      return x+k ; 
   }
   ll a=mod,b=mod,c=mod,d=mod;  
   if(n>2)
   {
      int x = n/3 ; 
         a = calco(n-(x*3),m,k+x*m);
      x--;
      if(x>0)
      {
         b = calco(n-(x*3),m,k+x*m);
      }
   }
   c = min(a,b) ; 
   if(n>1)
   {
      int x = n/2 ; 
         a = calco(n-(x*2),m,k+x*m);
      x--;
      if(x>0)
      {
         b = calco(n-(x*2),m,k+x*m);
      }
   }
   c = min(c,min(a,b)) ; 

   if(m>2)
   {
      int x = m/3 ; 
         a = calco(n,m-(x*3),k+x*n);
      x--;
      if(x>0)
      {
         b = calco(n,m-(x*3),k+x*n);
      }
   }
   c = min(c,min(a,b)) ;

    if(m>1)
   {
      int x = m/2 ; 
         a = calco(n,m-(x*2),k+x*n);
      x--;
      if(x>0)
      {
         b = calco(n,m-(x*2),k+x*n);
      }
   }
   c = min(c,min(a,b)) ;
   return c ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,m ;
      cin >> n >> m ;
      int ans = calco(n,m,0) ; 
      if(ans==mod){ans=0;}
      cout << ans << endl ;
   }
   return 0 ;
}