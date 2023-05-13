#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
struct com {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.ss==b.ss)
        {
          return a.ff > b.ff ; 
        }
        return a.second > b.second;
    }
};
int main()
{
   debugMode();
   priority_queue < pii , vector < pii> , com > pq ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      pq.push({x,y}) ; 
   }
   while(!pq.empty())
   {
      pii p = pq.top() ; pq.pop() ; 
      cout << p.ff << " " << p.ss << endl;
   }
   return 0 ;
}