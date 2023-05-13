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
const ll maxx = 262144+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
bool res ; 
ll calco(ll l,ll r)
{
  if(l+1==r)
  {
     if(ar[l]>ar[r])
     {
       swap(ar[l],ar[r]) ; 
       return 1 ; 
     }
     return 0 ; 
  }
  ll len = r-l+1 ; 
  len = len/2LL ; 
  ll l1 = l , r1 = l+len-1  ;
  ll l2 = r1+1 , r2 = r ;  
  ll a  = calco(l1,r1) ;
  ll b  = calco(l2,r2) ; 
  if(ar[l1]>ar[l2])
  {
     ll x = l1 ; 
     ll y = l2 ; 
     ll temp = len ; 
     while(temp--)
     {
        swap(ar[x],ar[y]) ; 
        x++ ; 
        y++ ; 
     }
     a++ ; 
  }
  if((ar[l1]+len)!=ar[l2]){res=false;}
  return (a+b) ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      for(int i=1;i<=n;i++)
      {
         cin >> ar[i] ; 
      }
      if(n==1)
      {
         cout << "0" << endl ; continue ; 
      }
      res = true ; 
      ll ans = calco(1,n) ; 
      if(!res){ans=-1;}
      cout << ans << endl ;
   }
   return 0 ;
}