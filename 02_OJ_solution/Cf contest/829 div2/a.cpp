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
int n,ar[50] ; 
int sett(int idx,int mask )
{
   mask = mask | (1<< (idx-1)) ; 
   return mask ; 
}
bool check(int idx,int mask )
{
   if( (mask&(1<<(idx-1))) ==0 )
   {
      return false ; 
   }
   return true ; 
}
int best = mod ;
bool dp[22][1<<22] ;  
void calco(int idx,int mask)
{
   if(dp[idx][mask])
   {
      return ; 
   }
   if(idx>n)
   {
      int g = 0,ans=0 ; 
      for(int i=1;i<=n;i++)
      {
         int x = ar[i] ; 
         if(check(i,mask))
         {
            x = __gcd(i,x) ; 
            ans+=(n-i+1) ; 
         }
         if(g==0){g=x;}
         else
         {
            g = __gcd(g,x) ; 
         }
      }
      if(g==1)
      {
         best = min(best,ans) ; 
      }
      return ; 
   }
   calco(idx+1,sett(idx,mask)) ; 
   calco(idx+1,mask) ; 
   dp[idx][mask] = true ; 
   return  ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      memset(dp,false,sizeof(dp)) ; 
      best = mod ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      calco(1,0) ; 
      cout << best << endl ;
   }
   return 0 ;
}