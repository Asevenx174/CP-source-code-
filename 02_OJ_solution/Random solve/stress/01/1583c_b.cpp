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
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
} 
int main()
{
   debugMode();
   int n,m ;
   cin >> n >> m ; 
   vector < vector < int > > br,cr ; 
   cr.resize(n+10, vector<int>(m+10));
   //br.resize(n+10, vector<int>(m+10));
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      for (int j = 0; j < m ; ++j )
      {
         int x = s[j]=='.' ? 0 : 1 ; 
         cr[i+1][j+1] = x ; 
      }
   }
   set < int > v ; 
   for(int i=2;i<=n;i++)
   {
      for(int j=2;j<=m;j++)
      {
         if(cr[i][j]==0 && cr[i-1][j]==1 && cr[i][j-1]==1)
         {
            v.insert(j) ; 
         }
      }
   }
   int q ;
   cin >> q ;
   while(q--)
   {
      int l,r,f=0 ;
      cin >> l >> r ; 
      auto it = v.upper_bound(l) ; 
      if(it!=v.end())
      {
         if(*it<=r){f=1;}
      }
      if(f)
      {
         cout << "NO" << endl ; 
      }
      else
      {
         cout << "YES" << endl ;
      }
   }
   return 0 ;
}