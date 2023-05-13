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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10],n ; 
ll d1,d2 ; 
void sett(ll x,ll y)
{
   ll g = __gcd(x,y) ; 
   x = x/g ; 
   y = y/g ; 
   d2 = x ; 
   d1 = y ; 
   return ;
}
void solve()
{
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] >> br[i+1] ; 
   }
   ll ans = 0 ; 
   ll idx = 1 ; 
   while(idx<n)
   {
    // cout << idx << endl ;
     ans++ ; 
     ll prev = 0 ; 
     while(idx<n)
     {
       ll l = idx ; 
       ll r = idx+1 ; 
       sett(br[l],br[r]) ;
       /*//cout << ar[l] << " --- " << ar[r] << endl ;
       //cout << d1 << " ??? " << d2 << endl ;
       //cout << (br[l]*(ar[l]/d1) ) << " " << (br[r]*(ar[r]/d2) ) << endl ;
       if(ar[l]%d1==zz && ar[r]%d2==zz)
       {
          ll m1 = ar[l]/d1 ; 
          ll m2 = ar[r]/d2 ;
          //if(prev>0){m1=prev;} 
          d1 = ar[l]/m1 ; 
          d2 = ar[r]/m2 ; 
          ll a = br[l]*d1 ;
          ll b = br[r]*d2 ; 
          //cout << m1 << " " << m2 << endl ;
          cout << a << " " << b << endl ;
          if(a!=b || (prev>zz && (prev!=a || prev!=b) ) ){break;}
          idx++ ; 
          prev = a ; 
       }
       else{break;} */
       if(ar[l]%br[r]==0 && ar[r]%br[l]==0)
       {
          ll m1 = ar[l]/br[r] ; 
          ll m2 = ar[r]/br[l] ; 
          ll a = br[l]*(ar[l]/m1) ;
          ll b = br[r]*(ar[r]/m2) ;
          cout << a << " " << b << endl ; 
          idx++ ; 
       }
       else{break;}
     }
     idx++ ;
     if(idx==n){ans++;} 
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}