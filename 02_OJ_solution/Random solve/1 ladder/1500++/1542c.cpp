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
#define pii                pair < long long , long long >

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
const ll maxx = 65 ,mod=1e9+7,imax=1e16,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< int > prime ;
void gen()
{
   for(int i=2;i<100;i++)
   {
      int f = 1 ; 
      for(int j=2;j<i;j++)
      {
         if(i%j==0){f=0;}
      }
      if(f){prime.push_back(i);}
   }
   return ; 
}
ll calco(ll r)
{
   vector < int > f(105,0) ; 
   for(int i=2;i<r;i++)
   {
      int temp = i ; 
      for(auto x : prime )
      {
         int co = 0 ; 
         while(temp%x==0)
         {
            temp = temp/x ;
            co++;
         }
         f[x] = max(f[x],co) ; 
      }
      if(temp>1){ f[temp] = max(1,f[temp]) ; }
   }
   ll mul = 1 ; 
   for(int i=2;i<maxx;i++)
   {
      int temp = f[i] ; 
      while(temp--)
      {
         mul = mul*i ; 
      }
   }
   return mul ; 
}
int main()
{
   debugMode();
   gen() ;
   std::vector< pii > pq ;
   for(int i=2;i<=42;i++)
   {
      ll ans = calco(i) ; 
      pq.push_back({ans,i}) ; 
   }

   ll test ;
   cin >> test ;
   while(test--)
   {

   ll n ;
   cin >> n ; 
   ll ans = 0 ; 
   for(int i=1;i<pq.size();i++)
   {
      pii p = pq[i-1] ; 
      pii q = pq[i]  ;
      ll x = p.ff ; 
      ll y = q.ff ; 
      ll j = p.ss ; 
      ll f = (n/x)-(n/y) ; 
      ll temp = (f*j)%mod ; 
      ans = (ans+temp)%mod ; 
   }
   cout << ans << endl ;

   }
   return 0 ;
}