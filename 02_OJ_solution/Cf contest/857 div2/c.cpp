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
const ll maxx = 200+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10][maxx+10],n,m ;  
void solve()
{
   cin >> n >> m ;
   ll f = 0 ; 
   for(int i=1;i<=n;i+=2)
   {
      ll val = f ; 
      for(int j=1;j<=m;j+=2)
      {
         ar[i][j] = val ; 
         if(j+1<=m){ar[i][j+1]=val+1;}
         if(i+1<=n)
         {
            ar[i+1][j]=val+2 ; 
            if(j+1<=m)
            {
               ar[i+1][j+1]=val+3 ; 
            }
         }
         val+=4ll ; 
      }
      f+=512LL ; 
   }
   cout << (n*m) << endl ;
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < m ; ++j)
      {
         if(j>0){cout << " " ; }
         cout << ar[i+1][j+1] ; 
      }
      cout << endl ;
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