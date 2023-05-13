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
const ll maxx = 5010 ,mod= 998244353 ,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll dp[maxx+10][maxx+10],f[maxx+10] ; 

vector<ll> fac,finv,inv;
void binom_init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}

int main()
{
   debugMode();

   map < char ,int > pq ; 
   char c = 'a' ;
   int idx = 1 ; 
   while(c<='z')
   {
      pq[c]=idx ;
      c++;
      idx++ ;  
   }
   string s ;
   cin >> s ;
   ll n = s.size() ; 
   for(auto c : s )
   {
      f[ pq[c] ]++ ; 
   }
   ll sum = 0 ; 
   dp[0][0] = 1 ; 
   for(int i=1;i<=26;i++)
   {
      for(ll j=0;j<=n;j++)
      {
         ll sum = 0 ; 
         for(int t=0;t<=min(j,f[i]);t++)
         {
            sum += ( dp[i-1][j-t]*binom(j,t) )%mod ; 
         }
         dp[i][j] = sum ; 
      }
   }
   ll to = 0 ;
   for(int i=1;i<=n;i++)
   {
      to = (to+dp[26][i])%mod ; 
   }
   cout << to << endl ;
   return 0 ;
}