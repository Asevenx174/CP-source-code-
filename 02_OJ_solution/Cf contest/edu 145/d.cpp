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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],lr[maxx+10],rr[maxx+10],n ; 
void solve()
{
   string s ;
   cin >> s ; 
   n = s.size() ; 
   int idx = 1 ; 
   for(auto c : s)
   {
      int x = c=='0' ? 0 : 1 ; 
      //cout << idx << " " << x << endl ;
      ar[idx++] = x ; 
   }
   int sum = 0 ; 
   for(int i=1;i<=n;i++)
   {
      lr[i] = sum ;
     // cout << i << " " << sum << endl ;
      if(ar[i]==1)
      {
         sum++ ; 
      } 
   }
   sum = 0 ; 
   for(int i=n;i>0;i--)
   {
      rr[i] = sum ;
    //  cout << i << " " << sum << endl ;
      if(ar[i]==0)
      {
         sum++ ; 
      } 
   }
   lr[0] = 0 ; 
   rr[n+1] = 0 ; 
   ll ans = 1e18+10 ; 
   ll add = 1e12 ; 
   for(int i=1;i<=n;i++)
   {
      ll a = lr[i]+rr[i] ; 
      ll b = 0 ; 
      if(i+1<=n && ar[i]==1 && ar[i+1]==0){a--;b++;}
      //cout << i << " " << lr[i-1] << " " << rr[i+1] << endl ;
      ll temp = a*(add+qq)+b*add ; 
      ans = min(ans,temp) ; 
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