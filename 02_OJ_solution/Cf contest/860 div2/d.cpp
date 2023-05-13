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
const ll maxx = 3e5+10,mod=1e18+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
void solve()
{
   cin >> n ;
   ll l = mod ; 
   ll r = -mod ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ;
      l = max(l,ar[i+1]) ; 
      r = min(r,ar[i+1]) ;  
   }
   ll d = r-l ; 
   ll p = 0 ; 
   set < ll > s ; 
   ll idx = 0 ; 
   ll ans = -mod ; 
   s.insert(zz) ; 
   for(int i=1;i<=n;i++)
   {
      p+=ar[i] ; 
      ll sub = p-d ; 
      auto it = upper_bound(s.begin(),s.end(),sub) ;
      if(it!=s.end())
      {
         sub = *it ; 
         if(sub>ans)
         {
            ans = sub ; 
            idx = i ; 
         }
      }
      s.insert(p) ; 
   }
   if(idx==0)
   {
      cout << "No" << endl ; return ; 
   }
   cout << "Yes" << endl ;
   ll sum = 0 ; 
   
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