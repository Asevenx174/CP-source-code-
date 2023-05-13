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
int ar[maxx+10],t,d ; // 0 based 
int st[maxx+10][26],n,lg[maxx+10],q,xr[maxx+10] ; // 26>= log2(maxx<=1e7)
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
int calco(int l,int r)
{
   int temp = r ; 
   int i = r+1 ; 
   while(l<=r)
   {
      int mid = (l+r)/2 ; 
      int val = getmax(mid,temp) ; 
      //cout << mid << " " << r << " " << val << endl ; 
      if(val>d)
      {
         l = mid+1 ; 
      }
      else{ i=mid ; r = mid-1 ; }
   }
   return i ; 
}
int main()
{
   debugMode();
   std::vector < int > v ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> xr[i] ; 
      v.push_back(xr[i]) ; 
   }
   for (int i = 1 ; i < n ; ++i)
   {
      ar[i] = xr[i]-xr[i-1] ; 
   }
   precom() ; 
   int q ; 
   cin >> q ;
   while(q--)
   {
      cin >> t >> d ; 
      auto it = upper_bound(v.begin(),v.end(),t) ;
      it-- ; 
      int k = it-v.begin() ; 
      //cout << k << endl ; 
      int i = calco(1,k) ;
      cout << i << endl ;  
   }
   return 0 ;
}