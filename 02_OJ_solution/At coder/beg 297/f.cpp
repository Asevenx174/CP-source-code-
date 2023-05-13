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
ll n,k,ar[maxx+10],pre[15][maxx+10] ; 
std::vector < ll > v ;
set < ll > ans ; 
ll f = 0 ;
bool dp[15] ; 
void calco(ll idx)
{
   if(dp[idx]){return;}
   if(idx>n)
   {  
      f++ ; 
      ll sum = 0 ;
      for (int i = 0; i < n ; ++i)
      {
         ll pos = v[i] ; 
         //cout << i << " " << v[i] << endl ; 
         ll add = pre[i+1][pos] ; 
         sum+=add ; 
      }
      cout << sum << endl ;
      if(sum>zz)
      {
         ans.insert(sum) ; 
      }
      return ;
   }
   for (int i = 0; i <=k ; ++i)
   {
      v.push_back(i) ; 
      calco(idx+1) ; 
      v.pop_back() ;   
   }
   dp[idx]=true ; 
}
void solve()
{
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for(int i=1;i<=n;i++)
   {
      for(ll j=1;j<=k;j++)
      {
         ll temp = j*ar[i] ; 
         pre[i][j] = temp ;
      }
   }
   calco(1) ; 
   cout << f << endl ;
   for(auto x : ans)
   {
      cout << x << endl ;
      k-- ; 
      if(k==zz)
      {
         cout << x << endl ; break ;  
      }
   }
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