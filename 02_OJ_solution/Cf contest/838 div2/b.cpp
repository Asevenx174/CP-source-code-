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
ll ar[maxx+10],n ; 
void solve()
{
   std::vector< pii > pq ;
   cin >> n ;
   for(ll i=1;i<=n;i++)
   {
      ll x ;
      cin >> x ;
      ar[i] = x ; 
      pq.push_back({x,i}) ; 
   }
   sort(pq.begin(),pq.end()) ; 
   std::vector < pii > ans ;
   ll p = pq[0].ff ; 
   for (int i = 1 ; i < pq.size() ; ++i)
   {
      ll x = pq[i].ff ; 
      ll t = x/p ; 
      if((x%p)!=zz){t++;}
      ll y = t*p ; 
      ll add = y-x ; 
      ans.push_back({pq[i].ss,add}) ;
      p = x+add ;  
   }
   cout << ans.size() << endl ; 
   for(auto x : ans)
   {
      cout << x.ff << " " << x.ss << endl ; 
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