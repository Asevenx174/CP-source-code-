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
int n,k,w,d,tr[maxx+10] ; 
void solve()
{
   cin >> n >> k >> d >> w ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      x+=w ; 
      tr[i+1] = x ; 
   }
   int idx = 1,ans=0 ; 
   while(idx<=n)
   {
      int a = idx ; 
      int b = min(n,idx+k-1) ;
      int pos = idx ; 
      while(a<=b)
      {
         int m = (a+b)/2 ; 
         int val = (tr[m]-w)-(tr[idx]) ; 
         if(val<=d)
         {
            pos = m ; 
            a = m+1 ; 
         }
         else
         {
            b = m-1 ; 
         }
      }
      //cout << idx << " " << pos << endl ;
      ans++ ; 
      idx = pos+1 ;   
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