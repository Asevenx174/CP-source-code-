#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 110 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         for (int j = 0; j < n ; ++j)
         {
            int x = s[j]=='0' ? 0 : 1  ; 
            ar[i+1][j+1] = x ; 
         }
      }
      int k = n /2,ans=0 ; 
      if(n%2==1)
      {
         int m = n/2+1 ; 
         int a = m ,b ;
         for (int i = 0; i +1 < m ; ++i)
         {
            b = i+1 ; 
            //cout << a << " " << b << endl ;
            map < int ,int > pq ; 
            pq[ ar[a][b]  ]++ ;
            pq[ ar[b][n-a+1] ]++ ; 
            pq[ ar[n-a+1][n-b+1] ]++ ; 
            pq[ ar[n-b+1][a] ]++ ; 
            ans+=( min(pq[0],pq[1]) )  ;
         }
         /*b = m ; 
         for (int i = 0; i +1 < m ; ++i)
         {
            a = i+1 ; 
            cout << a << " " << b << endl ;
            map < int ,int > pq ; 
            pq[ ar[a][b]  ]++ ;
            pq[ ar[b][n-a+1] ]++ ; 
            pq[ ar[n-a+1][n-b+1] ]++ ; 
            pq[ ar[n-b+1][a] ]++ ; 
            ans+=( min(pq[0],pq[1]) )  ;
         }*/
      } 
      //cout << ans << endl ;
      for(int i=1;i<=k;i++)
      {
         for(int j=1;j<=k;j++)
         {
            int a = i ; 
            int b = j ; 
            map < int ,int > pq ; 
            pq[ ar[a][b]  ]++ ;
            pq[ ar[b][n-a+1] ]++ ; 
            pq[ ar[n-a+1][n-b+1] ]++ ; 
            pq[ ar[n-b+1][a] ]++ ; 
            ans+=( min(pq[0],pq[1]) )  ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}