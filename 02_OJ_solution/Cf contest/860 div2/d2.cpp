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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

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
   queue < int > p,q ; 
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ; 
      if(x==0){continue;}
      if(x>0){p.push(x);}else{q.push(x);}
   }
   if(p.empty() && q.empty()){cout << "No" << endl ; return ;}
   cout << "Yes" << endl ;
   ll sum = 0 ; 
   ll idx = 1 ; 
   n = p.size()+q.size() ; 
   ll pos = 0 ; 
   ll best =-1e18,sub=0 ; 
   while(idx<=n)
   {
      if(sum<=zz)
      {
         ar[idx] = p.front() ; p.pop() ;  
      }
      else
      {
         ar[idx] = q.front() ; q.pop() ; 
      }
      cout << " " << ar[idx] ; 
      sum+=ar[idx] ; 
      if( (sum-sub)>best )
      {
         best = sum-sub ; 
         pos = idx ; 
      }
      sub = min(sub,sum) ; 
      idx++ ; 
   }
   cout << endl ;
   cout << pos << " " << best << endl ;
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