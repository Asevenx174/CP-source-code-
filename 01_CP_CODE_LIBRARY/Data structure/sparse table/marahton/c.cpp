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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; // 0 based 
int st[maxx+10][26],n,lg[maxx+10] ; // 26>= log2(maxx<=1e7)
int getgcd(int l,int r)
{
   int len = r-l+1 ;
   int j = lg[len] ; 
   int ans = __gcd(st[l][j],st[r-( (1<<j) - 1 )][j]) ; 
   return ans ; 
}
void precom() // nlogn
{
   lg[1] = 0 ; 
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
         st[i][j] = __gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]) ; 
      } 
   }
}

int main()
{
   debugMode();
   map < int ,int > pq ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      scanf("%d",&x) ;
      ar[i] = x ;  
   }
   precom() ; 
   for (int i = 0; i < n ; ++i)
   {
      int g = ar[i] ; 
      int l=i,r=n-1,k=-1 ; 
      while(l<=r)
      {
         int mid = (l+r)/2 ;
         int val = getgcd(i,mid) ;
         if(val<g)
         {
            r = mid-1 ; 
         }
         else
         {
            k = mid ; 
            l = mid+1 ; 
         }
      }
      if(k>=0)
      {
         cout << g << "  " << i << " " << k << endl ; 
         pq[g]+=(k-i+1) ; 
      }
   }
   int q ;
   cin >> q ;
   while(q--)
   {
      int g ; 
      scanf("%d",&g) ;
      printf("%d\n",pq[g]) ;  
   }
   return 0 ;
}