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
int n,m ; 

bool valid(vector < vector<int> > v,int len)
{
   vector < vector<int> > k (n+5,vector<int>(m+5)) ;
   vector < vector<int> > p (n+5,vector<int>(m+5)) ;
   for (int i = 0; i < n ; ++i)
   {
      int sum = 0 ; 
      for (int j = 0; j < m ; ++j )
      {
         int x = v[i+1][j+1] ; 
         if(x>=len)
         {
            k[i+1][j+1] = 1 ; 
         }
         else
         {
            k[i+1][j+1] = 0 ; 
         }
         sum+=k[i+1][j+1] ; 
         k[i+1][j+1] = sum ; 
         int add = 0 ; 
         if(i>0)
         {
            add = p[i][j+1] ; 
         }
         p[i+1][j+1] = sum+add ; 
         //cout << i+1 << " " << j+1 << " " << pr[i+1][j+1] << endl ;
         //cout << " " << p[i+1][j+1] ; 
      }
      //cout << endl ;
   }
   int val = len*len ; 
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         int x = i+len-1 ; 
         int y = j+len-1 ; 
         if(x>n || y>m){continue;}
         int ans = p[x][y]-p[i-1][y]-p[x][j-1]+p[i-1][j-1] ; 
         //cout << i << " " << j << " " << ans << endl ;
         if(ans==val){return true;}
      }
   }
   return false ; 
}
void solve()
{
   cin >> n >> m ; 
   vector < vector<int> > v (n+5,vector<int>(m+5)) ;
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < m ; ++j)
      {
         cin >> v[i+1][j+1] ; 
      }
   } 
  // bool temp = valid(v,3) ; 
//cout << temp << endl ;
  // return ; 
   int l=1,r=min(n,m),ans=1 ; 
   while(l<=r)
   {
      int mid = (l+r)/2 ; 
      if(valid(v,mid))
      {
         ans = mid ; 
         l = mid+1 ; 
      }
      else
      {
         r = mid-1 ; 
      }
   }
   cout << ans << endl ; 
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