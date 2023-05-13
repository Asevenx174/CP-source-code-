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
const ll maxx = 65 ,mod=998244353,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[10] = {0,0,1,1} ;
int fy[10] = {0,1,0,1} ;  
ll ar[5] ; 
bool dp[maxx+5][5] ; 
void up(ll idx)
{
   ar[idx]++ ; 
   ar[!idx]++ ; 
   if(ar[idx]==mod){ar[idx]=0;}
   if(ar[!idx]==mod){ar[!idx]=0;}
}
void draw()
{
   ar[2]++ ; 
   if(ar[2]==mod){ar[2]=0;}
}
void calco(ll n,ll idx)
{
   if(dp[n][idx]){return;}
   if(n==2)
   {
      up(idx);  
      draw() ; 
      return ; 
   }
   for (int i = 0; i < 4 ; ++i)
   {
      ll x = fx[i] ; 
      ll y = fy[i] ; 
      if(y==1)
      {
         up(idx) ; 
         up(!idx) ; 
      }
      else if(x==1)
      {
         calco(n-2,!idx) ; 
      }
      else
      {
         up(!idx) ; 
      }
   }
   dp[n][idx] = true ; 
   return ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ar[0] = 0 ; 
      ar[1] = 0 ; 
      ar[2] = 0 ; 
      ll n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         dp[i+1][0] = false ;
         dp[i+1][1] = false ;
         dp[i+1][2] = false ; 
      }
      calco(n,1) ; 
      cout << ar[0] << " " << ar[1] << " " << ar[2] << endl ;
   }
   return 0 ;
}