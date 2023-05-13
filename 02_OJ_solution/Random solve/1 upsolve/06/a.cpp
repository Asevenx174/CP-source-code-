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
const ll maxx = 3e5+10,mod=998244353,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx+10] ;
ll fastpow(ll n,ll k,ll p)
{
    ll ans = 1 ;
    while(k>0)
    {
        if(k&qq)
        { ans = (ans*n)%p; }
        k = k >> qq ;
        n = (n*n)%p;
    }
    return ans ;
} 
int main()
{
   debugMode();

   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ;
   }
   stack < pii > s ; 
   for(int i=1;i<=n;i++)
   {
      if(s.empty())
      {
         s.push( {ar[i],i} ) ; 
      }
      else
      {
         while(!s.empty() && s.top().ff>ar[i])
         {
            int x = s.top().ss ; 
            br[x] = i ; 
            s.pop() ; 
         }
         s.push({ar[i],i}) ; 
      }
   }
   ll sub = 0 ; 
   for(int i=1;i<=n;i++)
   {
      if(br[i]==0){continue;}
      ll l = i , r = br[i] ; 

      while(r>0)
      {
         ll len = r-l-1  ; 
         ll temp = fastpow(2LL,len,mod) ;
         sub = (sub+temp)%mod ;
         r = br[r] ; 
      } 
   }
   ll ans = 0  ;
   for(int i=2;i<=n;i++)
   {
      ll m = n-i+1 ;
      ll len = i-2 ; 
      ll temp =  fastpow(2LL,len,mod) ;
      temp = (temp*m)%mod ; 
      ans = (ans+temp)%mod ; 
   }
  // cout << ans << " " << sub << endl ; 
   ans = (ans-sub+mod)%mod ; 
   cout << ans << endl ;
   return 0 ;
}