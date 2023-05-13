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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m,ar[maxx+10][maxx+10],b,s1,s2 ; 
std::vector < int > v ;
int calco()
{
   int ans = 0 ; 
   int k = min(n,m)-1 ;
   int add = k*abs(b-s2) ; 
   ans+=add ; 
   k = (n*m)-k-1 ; 
   add = k*abs(b-s1) ; 
   ans+=add ; 
   return ans ; 
}
void solve()
{
  v.clear() ; 
  cin >> n >> m ; 
  for (int i = 0; i < n ; ++i)
  {
     for (int j = 0; j < m ; ++j)
     {
        int x ;
        cin >> x ;
        v.push_back(x) ;
     }
  }
  sort(v.begin(),v.end()) ; 
  int t = n*m ; 
  b = v[t-1] ; 
  s1 = v[0] ; 
  s2 = v[1] ; 
  int ans = calco() ; 
  sort(v.begin(),v.end(),greater<int>()) ;  
  b = v[t-1] ; 
  s1 = v[0] ; 
  s2 = v[1] ;
  //cout << b << " " << s1 << " " << s2 << endl ;
  ans = max(ans,calco()) ; 
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