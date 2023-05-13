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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
set < int > s ; 
int n,q ;
int calco(int idx)
{
   int sum = 0 ;
   int x = ar[idx] ; 
   while(x>9)
   {
      int d = x%10 ; 
      sum+=d ; 
      x = x/10 ; 
   }
   sum+=x ; 
   return sum ; 
}
void update(int l,int r)
{
   std::vector < int > v ;
   auto it = s.lower_bound(l) ; 
   while(it!=s.end() && *it<=r)
   {
      int idx = *it ; 
      ar[idx] = calco(idx) ; 
      if(ar[idx]<10)
      {
         v.push_back(idx) ; 
      }
      it++ ; 
   }
   for(auto x : v)
   {
      s.erase(s.find(x)) ; 
   }
}
void solve()
{
   s.clear() ; 
   cin >> n >> q ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      s.insert(i+1) ; 
   }
   for (int i = 0; i < q ; ++i)
   {
      int t ;
      cin >> t ;
      if(t==1)
      {
         int l,r ;
         cin >> l >> r ; 
         update(l,r) ; 
      }
      else
      {
         int idx ;
         cin >> idx ;
         cout << ar[idx] << endl ;
      }
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