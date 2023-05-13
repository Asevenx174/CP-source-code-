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
/*
1 2 3
3
1

1 2 3 4
3 4
1 4

1 2 3 4 5

3 4 5 // 1 3
1 4 5 // 2 4
1 2 5 // 3 5 //  
1 2 3 // 2,4 //

1 2 3 4 5 6 7 8

1 3


3 4 5 6 7 8 // 1 3

1 4 5 6 7 8 // 2 4

1 2 5 6 7 8 // (1 3)(2 4)




1 2 3 6 7 8
1 2 3 4 7 8 
1 2 3 4 5 8 
1 2 3 4 5 6

*/
int lr[maxx+10],rr[maxx+10] ; 
int ar[maxx+10],n,ans=0 ; 

void solve()
{
   cin >> n ; 
   ans = n-1 ; 
   string s ;
   cin >> s ; 
   for(int i=3;i<=n;i++)
   {
      if(s[i-1]==s[i-3]){ans--;} 
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