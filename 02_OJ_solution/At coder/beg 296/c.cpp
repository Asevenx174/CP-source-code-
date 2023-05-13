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
ll n,s1,s2,lr[maxx+10],rr[maxx+10],ar[maxx+10],br[maxx+10] ; 
void solve()
{
   ll l=0,r=0 ; 
   priority_queue < pii > pq ; 
   cin >> n >> s1 >> s2 ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      pq.push({x,i+1}) ; 
   }
   while(!pq.empty())
   {
      ll x  = pq.top().ff ; 
      ll idx = pq.top().ss ; 
      pq.pop() ;  
      ll p = lr[l]+s1 ; 
      ll q = rr[r]+s2 ;
      if(p>q)
      {
         br[++r] = idx ; 
         rr[r] = q ;  
      }
      else
      {
         ar[++l] = idx ; 
         lr[l] = p ; 
      }
   }
   cout << l ; 
   for (int i = 1 ; i <=  l ; ++i)
   {
      cout << " " ; 
      cout << ar[i] ; 
   }
   cout << endl ;
   cout << r ; 
   for (int i = 1 ; i <= r ; ++i)
   {
      cout << " " ; 
      cout << br[i] ; 
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