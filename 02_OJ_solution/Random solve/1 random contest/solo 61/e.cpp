#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair < int , pair < int,int > >
#define pi                 pair < int ,int >
///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool used[2*maxx+10] ; 
int main()
{
   debugMode();
   std::vector < pii > p ;
   int n ;
   cin >> n ;
   for (int i = 0; i < 2*n ; ++i)
   {
      int idx = i < n ? 1 : 2 ; 
      int x,y ;
      cin >> x >> y ; 
      p.push_back( {x,{idx,y}} ) ; 
   }
   sort(p.begin(),p.end(),greater<pii>()) ; 
   int ans = 0  ;
   for(int i=0;i<p.size();i++)
   {
      pii a = p[i] ; 
      if(a.sef==2){continue;}
      for(int j=0;j<p.size();j++)
      {
         pii b = p[j] ; 
         if(b.sef==1 || used[j] ) { continue ;}
         if(a.ses < b.ses && a.ff < b.ff )
         {
            ans++ ; 
            used[j]=true ; 
            break ; 
         }
      }
   }
   cout << ans << endl ; 
   return 0 ;
}