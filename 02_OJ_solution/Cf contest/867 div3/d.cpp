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
int ar[maxx+10],br[maxx+10],n ; 
void solve()
{
   cin >> n ; 
   int l=0,r=n-1 ; 
   int idx = 1 ; 
   while(idx<n)
   {
      br[idx] = l ; 
      br[idx+1] = r ; 
      l++ ; 
      r-- ; 
      idx+=2 ; 
   }
   if(n%2==1)
   {
      br[n] = l ;  
   }
   ar[1] = n ; 
   set < int > s ; 
   map < int , bool > pq ; 
   for(int i=2;i<=n;i++)
   {
      int r = br[i-1] ; 
      int b = br[i] ; 
      int need = 0 ; 
      //cout << r << " " << b << endl ;
      if(r<=b)
      {
         need = b-r ;
      }
      else
      {
         need = (n-r)+b ;  
      }
      ar[i] = need ;
      if(pq[need])
      {
         cout << "-1" << endl ; return ; 
      }
      pq[need] = true ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ; }
      cout << ar[i+1] ; 
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