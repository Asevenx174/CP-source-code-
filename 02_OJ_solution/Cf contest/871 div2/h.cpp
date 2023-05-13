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
ll dp[maxx+10][70],n,k,ar[maxx+10],lim=5 ; 
std::vector < int > pq[100] ;
int freq(int x)
{
   int f = 0 ; 
   int idx = 0 ; 
   while(1)
   {
      int temp = 1 << idx ; 
      if(temp>x){break;}
      if( (x&temp)!=0 ){f++;}
      idx++ ; 
   }
   return f ; 
}
void ini()
{
   for (int i = 0; i < lim ; ++i)
   {
      pq[freq(i)].push_back(i) ; 
   }
}
void solve()
{
  cin >> n >> k ;
  for (int i = 0; i < n ; ++i)
  {
     cin >> ar[i+1] ; 
  }
  for(int j=1;j<=n;j++)
  {
    for(int i=0;i<lim;i++)
    {
      dp[j][i] = 0 ; 
    }
  } 
  dp[1][ar[1]] = 1 ;
  for(int i=2;i<=n;i++)
  {
    for (int j = 0; j < lim ; ++j)
    {
       int v = ar[i] ; 
       int mask = (j&v) ;
       dp[i][mask] = dp[i-1][j]+dp[i][mask] ;
       dp[i][v] = dp[i-1][v]+1 ; 
       dp[i][j] = dp[i-1][j]+dp[i][j] ;  
       cout << i << " " << j << " " << dp[i][j] << endl ;
    }
  }
  cout << dp[2][1] << endl ;
  for(auto y : pq[k])
  {
    cout << y << " " << dp[n][y] << endl ;
  }
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