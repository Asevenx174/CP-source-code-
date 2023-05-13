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
int ar[maxx+10],n,k,br[maxx+10] ; 
void solve()
{
   cin >> n >> k ;
   for(int i=1;i<=n;i++)
   {
      cin >> ar[i] ; 
   } 
   std::vector < pii > ans ;
   for(int i=1;i<=k;i++)
   {
      map < int , bool > pq ; 
      int j = i ; 
      while(j<=n)
      {
         pq[ ar[j] ] = true ; 
         //cout << j << " + " << ar[j] << endl ;
         j+=k ; 
      }
      j = i ; 
      while(j<=n)
      {
         if(!pq[j]){
            //cout << i << " " << j << endl ; 
            ans.push_back({i,j});}
         //cout << j << " - " << pq[j] << endl ;
         j+=k ; 
      }
   }
   int res = 0 ; 
   if(ans.empty())
   {
      cout << res << endl ; return ; 
   }
   if(ans.size()==2 && ans[0].ff!=ans[1].ff){res=1;}
   else
   {
      res = -1 ; 
   }
   cout << res << endl ;
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