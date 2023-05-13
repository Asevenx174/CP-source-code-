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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; // 0 based 
int st[maxx+10][26],n,lg[maxx+10],q,m ; // 26>= log2(maxx<=1e7)
int getmax(int l,int r)
{
   int len = r-l+1 ;
   int j = lg[len] ; 
   int ans = max(st[l][j],st[r-( (1<<j) - 1 )][j]) ; 
   // [1,6] = [1,1+2^2-1] + [6-(2^2-1),6] = [1,4]+[3,6] 
   return ans ; 
}
void precom() // nlogn
{
   lg[1] = 0 ; // 1 can be divided 0 times by 2 
   for(int i=2;i<=maxx;i++)
   {
      lg[i] = lg[i/2]+1 ; 
   }  
   for (int i = 0; i < n ; ++i)
   {
      st[i][0] = ar[i] ; 
   }
   for(int j=1;j<=25;j++)
   {
      for (int i = 0; i + (1<<j) <= n ; ++i)
      {
         st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]) ; 
      } 
   }
}
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 0; i < m ; ++i)
   {
      cin >> ar[i] ; 
   }
   precom() ; 
   cin >> q ;
   while(q--)
   {
      int sx,sy,ex,ey,k ;
      cin >> sx >> sy >> ex >> ey >> k ; 
      int d1 = abs(sx-ex) ; 
      int d2 = abs(sy-ey) ; 
      int f = 1 ; 
      if( (d1%k)!=0 || (d2%k)!=0 )
      {
         f = 0 ; 
      }
      int l = min(sy,ey) ; 
      int r = max(sy,ey) ; 
      int best = getmax(l-1,r-1) ; 
      int p = (n-sx)/k-1 ;
      sx+=(p*k) ; 
      while(sx+k<=n){sx+=k;}
      if(sx<=best){f=0;}
      //cout << l << " " << r << " " << best << endl ;
      if(f)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}