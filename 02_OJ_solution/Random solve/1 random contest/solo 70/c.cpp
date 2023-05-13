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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int cr[5][5],ar[5],br[5] ; 
bool valid()
{
   for (int i = 0; i < 3 ; ++i)
   {
      for (int j = 0; j < 3 ; ++j )
      {
         int x = ar[i+1]+br[j+1] ; 
         if(x!=cr[i+1][j+1]){return false;}
      }
   }
   return true ; 
}
void solve()
{
    for (int i = 0; i < 3 ; ++i)
    {
       for (int j = 0; j < 3 ; ++j )
       {
          cin >> cr[i+1][j+1] ; 
       }
    }
    int f = 0 ; 
    for (int i = 0; i < 101 ; ++i)
    {
       ar[1] = i ; 
       br[1] = cr[1][1]-ar[1] ; 
       br[2] = cr[1][2]-ar[1] ; 
       br[3] = cr[1][3]-ar[1] ; 
       ar[2] = cr[2][1]-br[1] ; 
       ar[3] = cr[3][1]-br[1] ; 
       if(valid())
       {
          f = 1 ; 
       }
    }
    if(f)
    {
       cout << "Yes" << endl ;
    }
    else
    {
       cout << "No" << endl ;
    }
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