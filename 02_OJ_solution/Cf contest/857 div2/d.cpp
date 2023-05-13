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
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],n ; 
bool com(const pii &a,const pii &b)
{
   if(a.ff==b.ff)
   {
      return (a.ss>b.ss) ; 
   }
   else
   {
      return (a.ff>b.ff) ; 
   }
}
void solve()
{
   multiset < int > s ; 
   std::vector < pii > v ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int a,b ;
      cin >> a >> b ; 
      v.push_back({a,b}) ;
      s.insert(b) ;  
   }
   sort(v.begin(),v.end(),com) ; 
   int r = -mod ; 
   int ans = mod ; 
   for(auto p : v)
   {
      int a = p.ff ; 
      int b = p.ss ; 
     // cout << a << " " << b << endl ;
      s.erase(s.find(b)) ; 
      auto it = s.lower_bound(a) ; 
      int x = mod ; 
      int y = mod ; 
      if(it!=s.end())
      {
         x = *it ; 
         x = max(x,r) ; 
         ans = min(ans,abs(x-a)) ;  
      }
      if(it!=s.begin())
      {
         it-- ; 
         y = *it ;
         y = max(y,r) ;  
         ans = min(ans,abs(y-a)) ; 
      }
      //cout << r << endl ;
      if(r>=0)
      {
         ans = min(ans,abs(r-a)) ; 
      }
      r = max(r,b) ; 
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