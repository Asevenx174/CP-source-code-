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
const ll maxx = 1e3+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10],n,k ; 
void solve()
{
  cin >> n >> k ; 
  for (int i = 0; i < n ; ++i)
  {
     for (int j = 0; j < n ; ++j )
     {
        cin >> ar[i+1][j+1] ; 
     }
  }
  int h = n/2,d=0 ; 
  for(int i=1;i<=h;i++)
  {
     int a = n-i+1 ; 
     for(int j=1;j<=n;j++)
     {
       int b = n-j+1 ; 
       if(ar[i][j]!=ar[a][b]){d++;} 
     } 
  }
  if(n%2==1)
  {
     h = (n+1)/2 ; 
     for(int i=1;i<=h;i++)
     {
        if(ar[h][i]!=ar[h][n-i+1]){d++;}
     }
  }
  int have = k-d ; 
  if( have<0 || (have%2==1 && n%2==0) )
  {
     cout << "NO" << endl ;
  }
  else
  {
     cout << "YES" << endl ;
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