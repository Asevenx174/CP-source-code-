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
int ar[maxx+10],n,q ; 
int calco(int idx)
{
   while(idx+1<=n && ar[idx]>=ar[idx+1]){idx++;}
   return idx ; 
}
void solve()
{
   map < int , bool > pq ; 
   cin >> n >> q ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   int idx = 1 ; 
   std::vector < int > v ;
   while(idx<=n)
   {
      int l = idx ; 
      int r = calco(idx) ;
      if(l==r)
      {
         v.push_back(l) ; 
         pq[l] = true ; 
      } 
      else
      {
         v.push_back(l) ; 
         v.push_back(r) ; 
         pq[l] = true ; 
         pq[r] = true ; 
      }
      idx = r+1 ; 
   }
   vector < int > ans ; 
   for (int i = 0; i < q ; ++i)
   {
      int l,r ;
      cin >> l >> r ; 
      if(l==r){ans.push_back(1);continue;}
      else if(l+1==r)
      {
         ans.push_back(2) ; 
         continue ; 
      }
      auto it = lower_bound(v.begin(),v.end(),l) ;
      auto lt = upper_bound(v.begin(),v.end(),r) ;
      int add = (lt-it) ; 
      if(!pq[r]){add++;}
      if(!pq[l]){add++;}
      //add = max(add,2) ; 
      ans.push_back(add) ; 
   }
   for (int i = 0; i < q ; ++i)
   {
      cout << ans[i] << endl ; ; 
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}