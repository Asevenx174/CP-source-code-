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
ll n,c,d,ar[maxx+10] ; 
void solve()
{
   set < ll > s ; 
   cin >> n >> c >> d ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      s.insert(x) ; 
   }
   ll dlt = (n-(ll)s.size()) ;
   ll ans = dlt*c ; 
   priority_queue < ll > pq ; 
   for(auto x : s)
   {
      pq.push(x) ; 
   } 
   // << ans << endl ;
   ll len = s.size() ; 
   ll add = 1e18 ;  
   ll ex = 0 ; 
   while(!pq.empty())
   {
      ll x = pq.top() ; 
      pq.pop() ; 
      ll need = (x-len)*d ; 
      ll temp = ex+need ; 
      len-- ; 
      ex+=c ; 
      add = min(add,temp) ; 
   }
   ll temp = ex+d ; 
   add = min(add,temp) ;
   ans+=add ; 
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