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
const ll maxx = 3e5+10,mod=18,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2,N=18 ;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int A[maxx+10],F[maxx+10],n,ar[maxx+10],FS[maxx+10],N,n ; 

void getsubsets() ///O(N*2^K)
{
   //memory optimized, super easy to code.
   for(int i = 0; i<(1<<N); ++i)
   { 
      FS[i] = A[i] ;
      F[i] = A[i] ;   
   }
   for(int i = 0;i < N; ++i)
   {
     for(int mask = 0; mask < (1<<N); ++mask)
     {
      if((mask & (1<<i)) )
      {
         F[mask] += F[mask^(1<<i)] ; // sum of subsets 
      }
      else
      {
         FS[mask] += FS[mask^(1<<i)] ; // sum of supersets 
      }
     }
   }
}
void solve()
{
   cin >> n ; 
   N = ceil(log2(n)) ; 
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