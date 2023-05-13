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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,ans[maxx+10],po[maxx+10] ;
ll calco(ll len)
{
   ll sum = (po[len]-qq+mod)%mod ; 
   return sum ; 
}
void ini()
{
    ll pos = qq ; 
   po[0] = 1 ; 
   while(pos<maxx)
   {
      po[pos] = ( po[pos-qq]*tt )%mod ;
      pos++ ; 
   }
}
void solve()
{
   cin >> n ; 
   string s ;
   cin >> s ;
   ll idx = 1 ; 
   for(auto c : s)
   {
      int x = c=='0' ? 0 : 1 ; 
      ar[idx++] = x ; 
   }
   idx = n ; 
   ll sum = 0 ; 
   while(idx>0)
   {
      ll r = idx ; 
      ll l = idx ; 
      while(l-qq>zz && ar[l-qq]==ar[l])
      {
         l-- ; 
      }
      ll len = r-l+qq ; 
      ll add = calco(len) ; 
      sum = (sum+add)%mod ; 
      idx = l-qq ;  
   }
   cout << sum << endl ; 
}
int main()
{
   debugMode();
   ini() ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}