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
ll n,m ; 
std::vector < ll > v[maxx+10] ;
vector < ll > pq ; 
int lr[maxx+10],rr[maxx+10] ; 
ll prep()
{ 
   //cout << endl ;
   ll res = 0 ; 
   ll sum = 0 ; 
   ll co = 0 ; 
   for(int i=n-1;i>=0;i--)
   {
      ll x = pq[i] ; 
      ll sub = co*x ; 
      rr[i] = sum-sub ; 
      sum+=x ; 
      co++ ; 
   }

   co = 1 ; 
   lr[0] = 0 ; 
   for(int i=1;i<n;i++)
   {
      ll y = pq[i] ;
      ll x = pq[i-1] ;
      ll sub = (y-x)*co ; 
      lr[i] = lr[i-1]+sub ; 
      co++ ; 
   }
   ll ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      if(i>0)
      {
         ans+=lr[i] ; 
      }
      if(i+1<n)
      {
         ans+=rr[i] ; 
      }
   }
   //ans = ans/tt ; 
   //cout << ans << endl ;
   return ans ; 
}
void solve()
{
   cin >> n >> m ; 
   for (int i = 0; i < n+2; ++i)
   {
      v[i].clear() ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0 ; j < m ; ++j)
      {
         ll x ;
         cin >> x ; 
         v[i].push_back(x) ; 
      }
   }
   ll ans = 0 ; 
   for (int i = 0; i < m ; ++i)
   {
      pq.clear() ; 
      for (int j = 0; j < n ; ++j )
      {
         ll x = v[j][i] ; 
         pq.push_back(x) ; 
      }
      sort(pq.begin(),pq.end()) ; 
      ans+=prep() ; 
   }
   ans = ans/tt ; 
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