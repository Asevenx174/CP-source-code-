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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,d ; 
bool calco(int idx,int g)
{
   for(int i=1;i<=n;i++)
   {
      if(i==idx)
      {
         if(i==n)
         {
            int temp = d-ar[n-1]-1 ; 
            if(temp>=g){ return true ;}
         }
         else
         {
            int temp = ar[i+1]-ar[i-1]-2 ;
            temp = temp/2 ; 
            if(temp>=g){return true ;}
         }
      }
      else
      {
         int temp = ar[i]-ar[i-1]-2 ;  
         temp = temp/2 ; 
         if(temp>=g){return true ;}
      }
   }
   int temp = d-ar[n]-1 ; 
   if(temp>=g){ return true ; }
   return false ;
}
bool valid(int g)
{
   int f = 0,idx=0,jdx=0 ; 
   for (int i = 1 ; i <= n ; ++i)
   {
      int temp = ar[i]-ar[i-1]-1  ; 
      if(g>temp){f++; if(idx==0){idx=i;}else{jdx=i;} }
   }
   if(f==0){return true ;}
   if(f>2){return false ;}
   if(f==1)
   {
      if ( calco(idx,g) ) { return true ; }
      if(idx>1)
      {
         if ( calco(idx-1,g) ) { return true ; }
      }    
   }
   else if(idx+1==jdx)
   {
      int temp = ar[jdx]-ar[idx-1]-1 ; 
      if(temp<g){ return false ;}
      if ( calco(idx,g) ) { return true ; }
   }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int l=mod,r=mod ; 
      cin >> n >> d ; 
      for (int i = 1 ; i <= n ; ++i)
      {
         cin >> ar[i] ; 
         l = min(ar[i]-ar[i-1]-1,l) ; 
      }
      int ans = 0 ; 
      while(l<=r)
      {
         int mid = (l+r)/2 ; 
         if(valid(mid))
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
   return 0 ;
}