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
int ar[maxx+10] ; 
int calco(int i,int j)
{
   int x = ar[i] ; 
   int y = ar[j] ; 
   if(x==y){return 0;}
   if(y<x)
   {
      return (x-y) ; 
   }
   else
   {
      int ans = 26-abs(x-y) ; 
      return ans ; 
   }
}
string s ; 
ll br[maxx+10],cr[maxx+10] ; 
void ch(int idx,int f)
{
   f = f%26 ; 
   while(f--)
   {
      ar[idx]++ ; 
      if(ar[idx]>26)
      {
         ar[idx] = 1 ; 
      }
   }
}
void solve()
{
   int idx = 1 ; 
   for( auto c : s)
   {
      int x = c-'0'-48 ; 
      ar[idx++] = x ; 
   }
   int n = s.size() ; 
   if(n==1)
   {
      cout << "0" << endl ; return ;
   }
   idx = (n+1)/2 ; 
   idx++ ; 
   int i=idx-1,j=idx ; 
   if(n%2==1){i--;}
   ll ans = 0 ; 
   int pos = 0 ; 
   ll best = mod ; 
   ans = 0 ; 
   while(j<=n)
   {
      ll add = calco(i,j) ; 
      //cout << i << " " << j << " " << add << endl ;
      if(best==mod){ans+=add;ch(j+1,add);}
      else
      {
         ch(j+1,add-min(best,add)) ; 
      }
      best = min(best,add) ; 
      ans+=(add-best) ; 
      br[++pos] = add ; 
      j++ ; 
      i-- ; 
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   while(cin >> s)
   {
      solve() ; 
   }
   return 0 ;
}