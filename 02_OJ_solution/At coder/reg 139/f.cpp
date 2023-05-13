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
const ll maxx = 5010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10],n ; 
void shift(int idx)
{
   if(idx==n){idx--;}
   ll a = ar[idx] ; 
   ll b = ar[idx+1] ; 
   ll c = ar[idx-1] ; 
   ar[idx-1] = a ;
   ar[idx] = b  ;
   ar[idx+1] = c ; 
   return ; 
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> br[i+1] ; 
   }
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==br[i]){continue;}
      int j=i+1 ; 
      while(br[i]!=ar[j] && j<=n)
      {
         j++;
      }
      if(j>n){f=0;break;}
      while(i<j)
      {
         shift(j) ; 
         j-- ;
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(ar[i]!=br[i]){f=0;}
   }
   if(f)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ; 
   }
   return 0 ;
}