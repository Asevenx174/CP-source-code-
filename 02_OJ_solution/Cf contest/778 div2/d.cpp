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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll arr[maxx],brr[maxx],best[5][5],g[10][10]; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll A1=imax,AN=imax,BN=imax,B1=imax ; 
      ms(g,0) ; 
      ll n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> arr[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> brr[i+1] ; 
      }
      for(int i=2;i<n;i++)
      {
          ll a1 = abs(arr[1]-brr[i]) ; 
          ll an = abs(arr[n]-brr[i]) ; 

          ll b1 = abs(brr[1]-arr[i]) ; 
          ll bn = abs(brr[n]-arr[i]) ; 

          A1 = min(A1,a1) ; 
          AN = min(AN,an) ; 
          B1 = min(B1,b1) ; 
          BN = min(BN,bn) ; 
      }
      
      g[1][1] = abs(arr[1]-brr[1]) ;
      g[1][2] = A1 ;
      g[1][3] = abs(arr[1]-brr[n]) ; 

      g[2][1] = abs(arr[n]-brr[1]) ;
      g[2][2] = AN ;
      g[2][3] = abs(arr[n]-brr[n]) ; 

      g[3][1] = abs(arr[1]-brr[1]) ;
      g[3][2] = B1 ;
      g[3][3] = abs(arr[n]-brr[1]) ; 

      g[4][1] = abs(arr[n]-brr[n]) ;
      g[4][2] = BN ;
      g[4][3] = abs(arr[1]-brr[n]) ; 

      ll req = imax ; 
      for(int i=1;i<4;i++)
      {
         for(int j=1;j<4;j++)
         {
            for(int k=1;k<4;k++)
            {
               for(int p=1;p<4;p++)
               {
                  int a = 1 , b = 2 , c = 3 , d = 4 ; 
                  ll ans = g[a][i]+g[b][j]+g[c][k]+g[d][p] ; 
                  
                  if( (i==c && a==k) || (i==d && a==p) )
                  {
                      ans-=g[a][i] ; 
                  }

                  if( (j==c && b==k) || (j==d && b==p) )
                  {
                      ans-=g[b][j] ; 
                  }

                  req = min(req,ans) ; 
               }
            }
         }
      }

      cout << req << endl ;
      
   }
   return 0 ;
}