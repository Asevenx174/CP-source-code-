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
const ll maxx = 4e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll pr[maxx+10],qr[maxx+10],n ; 
void solve()
{
   ll a = 0 ; 
   cin >> n ; 
   ll sum = 0 ; 
   ll idx = 0 ; 
   for (int i = 0; i < 2*n ; ++i)
   {
      cin >> pr[i+1] ; 
      a+=max(pr[i+1],-pr[i+1]) ; 
      sum+=abs(pr[i+1]+1) ; 
   }
   if(n==1)
   {
      cout << abs(pr[1]-pr[2]) << endl ;
   }
   else if(n%2==1)
   {
      cout << a << endl ; return ;
   }
   else
   {
      ll b = 1e18 ; 
      for(int i=1;i<=2*n;i++)
      {
         ll temp = sum-abs(pr[i]+1)+abs(pr[i]-n) ; 
         b = min(b,temp) ; 
      }
      if(n==2)
      {
         ll c = 0 ; 
         for (int i = 0; i < 4 ; ++i)
         {
            c+=abs(pr[i+1]-tt) ; 
         }
         b = min(b,c) ; 
      }
      b = min(b,a) ; 
      cout << b << endl ;
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