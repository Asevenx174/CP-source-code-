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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,k,lr[maxx+10],rr[maxx+10] ; 
void solve()
{
   cin >> n >> k ; 
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s)
   {
      int x = c=='0' ? 0 : 1 ; 
      ar[idx++] = x ; 
   }
   ar[n+1] = 0 ; 
   lr[n+1] = 0 ; 
   rr[n+1] = 0 ; 
   idx = 1 ; 
   while(idx<=n)
   {
      int val = 0 ; 
      if(ar[idx])
      {
         val = 1 ; 
         if(ar[idx-1])
         {
            val+=lr[idx-1] ; 
         }
      }
      lr[idx] = val ; 
      idx++ ; 
   }
   idx = n ; 
   while(idx>0)
   {
      int val = 0 ; 
      if(ar[idx])
      {
         val = 1 ; 
         if(ar[idx+1])
         {
            val+=rr[idx+1] ; 
         }
      }
      rr[idx] = val ; 
      idx-- ; 
   }
   int ans = 0 ; 
   for(int i=k;i<=n;i++)
   {
      int a = lr[i-k] ; 
      int b = rr[i+1] ; 
      int temp = a+b+k ; 
      ans = max(ans,temp) ; 
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