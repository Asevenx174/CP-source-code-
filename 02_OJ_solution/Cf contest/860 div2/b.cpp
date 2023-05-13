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
const ll maxx = 50000+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector < int > v[maxx+10] ;
void solve()
{
   map < int ,int > f ; 
   int m ; 
   cin >> m ;
   for (int i = 0; i < m ; ++i)
   {
      v[i].clear() ; 
      int n ;
      cin >> n ;
      for (int j = 0; j < n ; ++j)
      {
         int x ;
         cin >> x ;
         v[i].push_back(x) ; 
         f[x]++ ; 
      }
   }
   vector < int > ans ; 
   for (int i = 0; i < m ; ++i)
   {
      int temp = 0 ;
      for(auto x : v[i])
      {
         if(f[x]==1 && temp==0)
         {
            temp = x ; 
         }
         f[x]-- ; 
      }
      if(temp==0)
      {
         cout << "-1" << endl ; return ;
      }
      ans.push_back(temp) ; 
   }
   int idx = 0 ; 
   for(auto x : ans )
   {
      if(idx){cout << " " ;}
      cout << x ; 
      idx = 1 ; 
   }
   cout << endl ;
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