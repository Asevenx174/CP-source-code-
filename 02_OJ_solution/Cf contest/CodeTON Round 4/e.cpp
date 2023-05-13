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
#define un                 unordered_map < long long , long long  >

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
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
ll n,q,ar[maxx+10],pr[maxx+10] ; 
std::vector < un > v(maxx+10) ;
ll calco(ll x,ll y)
{
   if(x==0){return 0;}
   un k = v[x] ; 
   ll val = k[y] ; 
   if(val==zz)
   {
      val = calco(pr[x],pr[y])+(ar[x]*ar[y]) ;  
      k[y] = val ; 
   }
   return val ; 
}
void solve()
{
   cin >> n >> q ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for(int i=2;i<=n;i++)
   {
      cin >> pr[i] ; 
   }
   vector < ll > ans ; 
   for (int i = 0; i < q ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      ll temp = calco(x,y) ; 
      ans.push_back(temp) ; 
   }
   for (int i = 0; i < ans.size() ; ++i)
   {
      cout << ans[i] << endl ; 
   }
   cout << endl ;
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