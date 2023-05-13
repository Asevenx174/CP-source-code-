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
ll l,r ; 
bool calco(ll a,ll b,ll n)
{
   ll x = (a-b)*(n-qq)+qq ;
   ll y = (a-b)*(n-qq)+a ;
   if(l<zz)
   {
      l = x ; 
      r = y ; 
   }
   a = max(l,x) ; 
   b = min(r,y) ; 
   if(a<=b)
   {
      l = a ; 
      r = b ; 
      return true ; 
   } 
   return false ;
}
ll check(ll a,ll b)
{
   ll p=1,q=mod,k ; 
   while(p<=q)
   {
      ll m = (p+q)/tt ; 
      ll temp = (a-b)*(m-qq) ; 
      ll x = temp+qq ; 
      ll y = temp+a ; 
      cout << x << " " << y << endl ;
      if(y<l)
      {
         p = m+qq ; 
      }
      else if(r<x)
      {
         q = m-qq ; 
      }
      else if(x<=l && r<=y)
      {
         return m ; 
      }
      else
      {
         return -1 ;
      }
   }
   return -1 ; 
}
void solve()
{
   std::vector < int > v ;
   l = -mod ; 
   ll q ;
   cin >> q ;
   ll f = 0 ; 
   while(q--)
   { 
      cout << l << " " << r << endl ;
      ll t ; 
      cin >> t ; 
      ll a,b,n ; 
      if(t==qq)
      {
         f = 1 ; 
         cin >> a >> b >> n ; 
         if(calco(a,b,n))
         {
            v.push_back(1) ; 
         }
         else
         {
            v.push_back(0) ; 
         }
         //cout << x << " " << y << endl ;
      }
      else
      {
         cin >> a >> b ; 
         if(l<zz)
         {
            v.push_back(-1) ; continue ;
         }
        // cout << l << " " << r << endl ;
         v.push_back(check(a,b)) ;
      }
   }
   for (int i = 0; i < v.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << v[i] ; 
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