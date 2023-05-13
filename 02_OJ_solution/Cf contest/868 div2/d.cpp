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
int n,k,xr[maxx+10],cr[maxx+10],ans[maxx+10] ; 
void solve()
{
   cin >> n >> k ; 
   for (int i = 0; i < n+5 ; ++i)
   {
      ans[i] = 0 ; 
   }
   for (int i = 0; i < k ; ++i)
   {
      cin >> xr[i+1] ; 
   }
   for (int i = 0; i < k ; ++i)
   {
      cin >> cr[i+1] ; 
   }
   if(cr[1]>xr[1])
   {
      cout << "NO" << endl ; return ; 
   }
   for(int i=2;i<=k;i++)
   {
      if((xr[i]-xr[i-1])<((cr[i]-cr[i-1])) || cr[i]>xr[i])
      {
         cout << "NO" << endl ; return ; 
      }
   }
   cout << "YES" << endl ;
   int p = 4 ; 
   xr[0] = 3 ; 
   cr[0] = 3 ; 
   for(int i=1;i<=k;i++)
   {
      if(i==1 && xr[i]==3){continue;}
      int need = cr[i]-cr[i-1] ; 
      int idx = xr[i] ; 
      while(need--)
      {
         ans[idx--] = p ; 
      }
      p++ ; 
   }
   int val = 1 ; 
   for(int i=1;i<=n;i++)
   {
      if(ans[i]!=0){continue;}
      ans[i] = val ; 
      val++ ; 
      if(val>3){val=1;}
   }
   for(int i=1;i<=n;i++)
   {
      char ch = 'a'+(ans[i]-1) ; 
      cout << ch ; 
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