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
int ar[maxx+10],n,kr[maxx+10],m,len=0 ; 
bool check(int l,int r)
{
   map < int ,int > pq ; 
   for(int i=l;i<=r;i++)
   {
      pq[ ar[i] ]++ ; 
   }
   for(int i=1;i<=m;i++)
   {
      if(pq[i]!=kr[i]){return false;}
   }
   return true ; 
}
void solve()
{
   len = 0 ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> kr[i+1] ; 
      len+=kr[i+1] ; 
   }
   int f = 0 ; 
   for(int i=1;i+len-1<=n;i++)
   {
      if(check(i,i+len-1))
      {
         cout << "YES" << endl ; return ; 
      }
   }
   cout << "NO" << endl ;
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