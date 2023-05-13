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
const ll maxx = 50+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

void solve()
{
   std::vector < int > ar(maxx+10,0),br(maxx+10,0) ;
   int n,k ;
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      int a,b ;
      cin >> a >> b ; 
      if(a<=k && k<=b)
      {
         ar[a]++ ; 
         ar[b+1]-- ; 
      }
   }
   map < int , int > pq ; 
   int sum = 0,best=0 ; 
   for(int i=1;i<=50;i++)
   {
      sum+=ar[i] ; 
      br[i] = sum ; 
      pq[sum]++ ; 
      best = max(best,sum) ; 
   }
   if(best==br[k] && pq[best]==1)
   {
      cout << "YES" << endl ;
   }
   else
   {
      cout << "NO" << endl ;
   }
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