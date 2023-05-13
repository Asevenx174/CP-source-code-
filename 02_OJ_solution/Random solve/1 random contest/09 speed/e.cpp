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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2000+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10],cr[maxx+10][maxx+1],n,m,pre[maxx][maxx+10],f[maxx][maxx],lim ; 
ll best = 0 ; 
bool calco(int i,int j)
{
   int a = i ;
   int b = j ; 
   while(a<=n)
   {
      b = j ; 
      while(b<=m)
      {
         if((a-i)<0 || (b-j)<0){continue;}
         ll ans = f[a][b]-f[a-i][b]-f[a][b-j]+f[a-i][b-j] ; 
         if(ans<=lim)
         { 
            return true;
         }
         b++ ;
      }
      a++ ;  
   }
   swap(i,j) ; 
   a = i ; 
   while(a<=n)
   {
      b = j ; 
      while(b<=m)
      {
         if((a-i)<0 || (b-j)<0){continue;}
         ll ans = f[a][b]-f[a-i][b]-f[a][b-j]+f[a-i][b-j] ; 
         if(ans<=lim)
         { 
            return true;
         }
         b++ ;
      }
      a++ ;  
   }
   return false ; 
}
bool valid(int k)
{
   if(k==0){return true;}
   for(int i=1;i*i<=k;i++)
   {
      if(k%i==0)
      {
         int j = k/i ;
         if(calco(i,j))
         {
            return true ; 
         }     
      }
   }
   return false ; 
}
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 0; i < n; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> br[i+1] ; 
   }
   cin >> lim ; 
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < m ; ++j )
      {
          cr[i+1][j+1] = ar[i+1]*br[j+1] ; 
      }
   }
   for(int i=1;i<=n;i++)
   {
      ll sum = 0 ; 
      for(int j=1;j<=m;j++)
      {
         sum+=cr[i][j] ; 
         pre[i][j] = sum ; 
      }
   }
   for(int i=1;i<=m;i++)
   {
      ll sum = 0 ; 
      for(int j=1;j<=n;j++)
      {
          sum+=pre[j][i] ; 
          f[j][i] = sum ; 
          //cout << i << " " << j << " -> " << sum << endl ;
      }
   }
   int l=0,r=n*m ; 
   while(l<=r)
   {
      int mid = (l+r)/2 ; 
      if(valid(mid))
      {
         l = mid+1 ; 
         best = mid ; 
         //cout << mid << endl ; 
      }
      else
      {
         r = mid-1 ; 
      }
   }
   cout << best << endl ;
   return 0 ;
}