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
int ar[maxx+10],br[maxx+10] ; 
void solve()
{
  priority_queue < int > pq ; 
  int n,m ;
  cin >> n >> m ;
  std::vector < int > ans(n+5,-1) ;
  for (int i = 0; i < n ; ++i)
  {
     pq.push(i+1) ; 
  }
  for (int i = 0; i < m ; ++i)
  {
     cin >> ar[i+1] ; 
  }
  set < int > s ; 
  for (int i = 0; i < m  ; ++i)
  {
     int x = ar[i+1] ; 
     auto it = s.find(x) ; 
     if(it==s.end())
     {
        if(!pq.empty())
        {
           ans[pq.top()] = i+1 ; pq.pop() ; 
        }
     }
     s.insert(x) ; 
  }
  for (int i = 0; i < n ; ++i)
  {
     if(i>0){cout << " " ;}
     cout << ans[i+1] ; 
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