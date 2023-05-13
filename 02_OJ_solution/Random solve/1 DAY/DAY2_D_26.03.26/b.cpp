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
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int minnum(string s)
{
   int n = s.size() ; 
   int idx = 1 ; 
   for(auto c : s)
   {
     ar[idx++] = c=='0' ? 0 : 1 ; 
   }
   int a = n/2 ; 
   int b = n/4 ; 
   int sum = 0 ; 
   for(int i=1;i<n;i++)
   {
      if(ar[i]==ar[i+1] && ar[i]==1 && b>0)
      {
         ar[i+1] = 0 ; b-- ; 
      }
      sum+=ar[i] ; 
      //cout << ar[i] << endl ;
   }
   //cout << ar[n] << endl ;
   sum+=ar[n] ; 
   return sum ; 
}
int maxnum(string s)
{
   int n = s.size() ; 
   int idx = 1 ; 
   for(auto c : s)
   {
     ar[idx++] = c=='0' ? 0 : 1 ; 
   }
   int sum = 0 ;
   int a = n/2 ; 
   int b = n/4 ; 
   //std::vector < pii > v ;
   idx = 1 ; 
   while(idx<=n)
   {
      if(ar[idx]==0){idx++;continue;}
      int l = idx ; 
      int r = idx ; 
      while(r+1<=n && ar[r+1]==1)
      {
         r++ ; 
      }
      if(ar[l-1]==0 && ar[l]==1 && b>0)
      {
         ar[l] = -1 ; 
         ar[l-1] = -1 ; 
         sum++ ; 
         b-- ; 
      }
      if(ar[r]==1 && ar[r+1]==0 && r+1<=n && b>0)
      {
         ar[r] = -1 ; 
         ar[r+1] = -1 ;
         sum++ ; 
         b-- ; 
      }
      idx = r+1 ; 
   }
   for(int i=2;i<=n;i++)
   {
      if(ar[i]==ar[i-1] && ar[i]==0 && b>0)
      {
         ar[i] = -1 ; 
         ar[i] = -1 ; 
         b-- ; 
      }
   }
   for(int i=2;i<=n;i++)
   {
      if(ar[i]==ar[i-1] && ar[i]==1 && b>0)
      {
         ar[i] = -1 ; 
         ar[i] = -1 ; 
         b-- ; 
         sum++ ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      if(ar[i+1]==1){sum++;}
   }
   return sum ; 
}
void solve()
{
   int n,m,a=0,b=0 ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      a+=minnum(s) ; 
      b+=maxnum(s) ; 
      //cout << minnum(s) << " " << maxnum(s) << endl ;
   }
   cout << a << " " << b << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
  // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}