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
const ll maxx = 30+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,ar[maxx+10] ; 
string s ; 
std::vector < int > v,g[maxx+5] ; 
int calco(int idx)
{
   if(g[idx].size()==n){return 0;}
   set < int > ase ; 
   for (int i = 0; i < n ; ++i)
   {
      ase.insert(i+1) ; 
   }
   for(auto x : g[idx])
   {
     ase.erase(ase.find(x)) ; 
   }
   sort(g[idx].begin(),g[idx].end()) ; 
   int temp = 0 ; 
   while(1)
   {
      temp++ ; 
      vector < int > d ; 
      auto it = ase.begin() ; 
      int p = *it ; 
      d.push_back(p) ; 
      int gap = 0 ; 
      while(1)
      {
         it++ ; 
         if(it==ase.end()){break;}
         int q = *it ; 
         auto pq = upper_bound(g[idx].begin(),g[idx].end(),p) ;
         if( gap || (pq!=g[idx].end() && (*pq)<q) )
         {
            d.push_back(q) ;
            p = q ; 
            gap = 0 ; 
         }
         else
         {
            gap = 1 ; 
         } 
      }
      for(auto x : d)
      {
         ase.erase(ase.find(x)) ; 
      } 
      if(ase.empty()){return temp;}
   }
}
void solve()
{
   cin >> s ; 
   n = s.size() ; 
   for (int i = 0; i < 30 ; ++i)
   {
      g[i].clear() ; 
   }
   int idx = 1 ; 
   while(idx<=n)
   {
      int x = s[idx-1]-'a'+1 ; 
      g[x].push_back(idx) ; 
      idx++ ; 
   }
   int ans = mod ; 
   for(int i=1;i<27;i++)
   {
      int temp = calco(i) ; 
      ans = min(ans,temp) ; 
   }
   cout << ans << endl ;
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