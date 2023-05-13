#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 200+10,mod=1e9+7,MOD=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
vector<int> fac;
vector<int> ifac;

int binExp(int base, int exp) {
    base %= MOD;
    int res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (int) ((long long) res * base % MOD);
        }
        base = (int) ((long long) base * base % MOD);
        exp >>= 1;
    }
    return res;
}

void precompute(int n) {
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = (int) ((long long) i * fac[i-1] % MOD);
    }

    ifac.resize(n + 1);
    for (int i = 0; i < fac.size(); i++) {
        ifac[i] = binExp(fac[i], MOD - 2);
    }
    return;
}

int ncr(int n, int r) {
    if ((n < 0) || (r < 0) || (r > n)) {
        return 0;
    }
    return (int) ((long long) fac[n] * ifac[r] % MOD * ifac[n - r] % MOD);
}

int main()
{
   debugMode();
   precompute(maxx);
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,i,j,x,y ;
      cin >> n >> i >> j >> x >> y ; 
      if(x>y)
      {
        swap(x,y) ; 
        ll l = n-j+1 ; 
        ll r = n-i+1 ; 
        i = l ; 
        j = r ; 
      }
      ll ans = qq ; 
      ll temp = 1 ; 

      ll add = 0 ; 
      for(int k=i+1;k<j;k++)
      {
         temp = ncr(n-y-qq,j-k-qq) ;
         add = (add+temp)%mod ;  
      }
      temp = ncr(x-qq,i-qq) ; 
      add = (add*temp)%mod ; 
      temp = ncr(y-x-qq,n-j-x+i) ; 
      add = (add*temp)%mod ;
      ll ans1 = add ;  
      
      //cout << add << endl ;

      add = 0 ; 
      for(int k=j+1;k<n;k++)
      {
         temp = ncr(n-y-qq,k-j-qq) ;
         add = (add+temp)%mod ;  
      }
      temp = ncr(x-qq,i-qq) ; 
      add = (add*temp)%mod ; 
      temp = ncr(y-x-qq,j-i-qq) ; 
      add = (add*temp)%mod ;
      ll ans2 = add ; 
      ans = (ans1+ans2)%mod ;  
      
      if(y==n)
      {
        ll a = ncr(x-qq,i-qq) ;
        ll b = ncr(y-x-qq,j-i-qq) ;
        add = (a*b)%mod ;   
        if(j==n){add=0;}
        ans = (ans+add)%mod ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}