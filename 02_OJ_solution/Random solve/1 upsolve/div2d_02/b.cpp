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
const ll maxx = 2e5+10,mod=998244353,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],lim ; 
std::vector < int > pr[maxx+10] ;
void primeFactors(int n,int idx)
{
   while (n % 2 == 0)
   {
      pr[idx].push_back(2) ; 
      n = n/2;
   }
   for (int i = 3; i <= sqrt(n); i = i + 2)
   {
      while (n % i == 0)
      {
         pr[idx].push_back(i) ;
         n = n/i;
      }
   }
   if (n > 2)  { pr[idx].push_back(n) ; }
}
ll calco(int idx)
{
   ll mul = 1 ; 
   set < int > s ; 
   map < int ,int > a,b ; 
   for(auto x : pr[idx-1] )
   {
      a[x]++ ; 
      s.insert(x) ;
   }
   for(auto x : pr[idx] )
   {
      b[x]++ ; 
   }
   cout << idx << " -->> " << endl ;
   for(auto x : s )
   {
      cout << x << " " << a[x] << " " << b[x] << endl ;
      if(a[x]>b[x])
      {
         mul = mul*x ; 
      }
   }
   ll ans = lim-((ll)lim/mul)-(ar[idx]-1) ;
   return ans ;  
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int f = 1 ; 
      int n ;
      cin >> n >> lim ;
      for (int i = 0; i < n ; ++i)
      {
         pr[i].clear() ; 
         int x ;
         cin >> x ;
         ar[i] = x ; 
         primeFactors(x,i) ; 
         if(i>0)
         {
            if(ar[i-1]<ar[i])
            {
               f = 0 ;
            }
            else if(ar[i-1]%ar[i]!=0)
            {
               f = 0 ; 
            }
         }
      }
      if(!f)
      {
         cout << f << endl ; continue ; 
      }
      ll ans = 1 ; 
      for (int i = 1 ; i < n ; ++i)
      {
         ll mul = calco(i) ;
         //cout << i << " " << mul << endl ;
         ans = (ans*mul)%mod ;  
      }
      ans = (ans+qq)%mod ;
      cout << ans << endl ;
   }
   return 0 ;
}