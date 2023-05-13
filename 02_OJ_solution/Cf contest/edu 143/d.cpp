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
const ll maxx = 3e5+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,tr[5] ; 
ll calco(ll idx)
{
   tr[1] = ar[idx] ;
   tr[2] = ar[idx-qq] ;
   tr[3] = ar[idx-tt] ; 
   sort(tr+qq,tr+3LL+qq) ; 
   ll ans = qq ; 
   if(tr[1]==tr[2] && tr[2]==tr[3] && tr[1]==tr[3])
   {
      ans = 6 ; 
   }
   else if(tr[1] < tr[2] && tr[2] < tr[3])
   {
      ans = 2 ; 
   }
   else if(tr[1]==tr[2])
   {
      ans = 4 ; 
   }
   else
   {
      ans = 2 ; 
   }
   cout << ans << endl ;
   return ans ; 
}
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ll ans = qq ; 
   std::vector< ll > k ;
   for(int i=3;i<=n;i+=3)
   {
      //ans = (ans*calco(i))%mod ; 
      k.push_back(calco(i)) ; 
   }
   sort(k.begin(),k.end(),greater<ll>()) ; 
   int lim = (int)k.size() ; 
   lim = lim / 2 ; 
   for (int i = 0 ; i < k.size()  ; ++i)
   {
      ll x = k[i] ; 
      ans = (ans*x)%mod ;
   }
   cout << ans << endl ; 
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}