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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,ar[maxx+10] ; 
ll calco(ll l,ll r)
{
  // cout << l << " " << r << endl ;
   if(l==r){return qq;}
   ll len = r-l+qq ; 
   ll a = len/tt ; 
   ll b = len-(a-qq) ; 
   ll ans = a*b ; 
   if(len%tt!=zz){a++;}
   b = len-(a-qq) ; 
   ans = max(ans,a*b) ;
   return ans ; 
}
ll pre(ll x,ll y)
{  
   if(min(x,y)==zz){return zz;}
   ll len = x+y ;
   if(len>=n){return zz;}
   ll a = len/tt ; 
   ll b = len-(a-qq) ; 
   ll ans = a*b ; 
   if(len%tt!=zz){a++;}
   b = len-(a-qq) ; 
   ans = max(ans,a*b) ;
   return ans ; 
}
void solve()
{
   int idx = 1 ; 
   string s ;
   cin >> s ;
   n = s.size() ; 
   int f = 1 ; 
   for(auto c : s)
   {
      ar[idx] = c=='0' ? 0 : 1 ; 
      if(ar[idx]==0){f=0;}
      idx++ ; 
   }
   idx = 1 ; 
   ll ans = 0 ; 
   while(idx<=n)
   {
      if(ar[idx]==0){idx++;continue;}
      ll l = idx ; 
      ll r = idx ; 
      while(r+qq<=n && ar[r+qq]){r++;}
      //cout << l << " " << r << endl ;
      ans = max(ans,calco(l,r)) ; 
      idx = r+qq ; 
   } 
   ll a=0,b=0 ; 
   idx = 1 ; 
   while(idx<=n && ar[idx]){idx++;a++;}
   idx = n ; 
   while(idx>zz && ar[idx]){idx--;b++;}
   ans = max(ans,pre(a,b)) ;  
   if(f)
   {
      ans = n*n ; 
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