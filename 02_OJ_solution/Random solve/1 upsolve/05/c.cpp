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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1005,imax=2e9+10,qq=1,zz=0;
 
inline void debugMode() 
{
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}
int ar[maxx+10],f[mod+5] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      vector < vector < int > > v ; 
      ms(f,0) ; 
      int n,k ;
      scanf("%d %d",&n,&k) ; 
      for(int i=1;i<=n;i++)
      {
         int x ;
         scanf("%d",&x) ; 
         ar[i] = x ; 
         int r = x%k ; 
         f[r]++ ;
      }
      v.resize(k+5) ; 
      for (int i = 0; i < k ; ++i)
      {
         v[i].resize(f[i]+5) ; 
      }
      ms(f,0) ; 
      for(int i=1;i<=n;i++)
      {
         int r = ar[i]%k ; 
         f[r]++ ; 
         v[r][f[r]] = i ; 
      }
      ll ans = 0 ; 
      for(int r=0;r<k;r++)
      {
         int i = 0 ; 
         while(1)
         {
         int flag = 0 ; 
         while(i<k)
         {
             int j = r-i ; 
             if(j<0)
             {
                j = k-i+r ;  
             }
             if(i==j)
             {
                if(f[i]>1)
                { 
                   ll a = v[i][f[i]] ; 
                   ll b = v[i][f[i]-1] ; 
                   ans+=( ll(ar[a]+ar[b])/k ) ;
                   f[i]-=2 ; 
                   flag = 1 ; 
                   break ; 
                }
             }
             else if(j<k)
             {
                if( min(f[i],f[j])>0 )
                {
                   ll a = v[i][f[i]] ; 
                   ll b = v[j][f[j]] ; 
                   ans+=( ll( ar[a]+ar[b] )/k ) ;
                   f[i]-- ; 
                   f[j]-- ; 
                   flag = 1 ;
                   break ; 
                }
             }
             i++;
          }
          if(flag==0){break;}
        }
      }
      printf("%lld\n",ans) ; 
   }
   return 0 ;
}