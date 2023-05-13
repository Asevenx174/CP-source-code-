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
int ar[maxx+10],br[maxx+10],cr[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
       ms(br,0) ; 
       int n,k,temp=0;
       cin >> n >> k ;
       temp = k ; 
       string s ;
       cin >> s ;
       int idx = 1 ; 
       for(auto c : s )
       {
         int x = c=='1' ? 1 : 0 ; 
         ar[idx] = x ; 
         cr[idx] = x ; 
         idx++ ;  
       }
       idx = 1 ; 
       while(k>0 && idx<n)
       {
          int a = ar[idx] ; 
          if( (a==1 && k%2==1) || (a==0 && k%2==0) )
          {
             br[idx]++ ; 
             k-- ;
          }
          cr[idx] = 1 ; 
          idx++ ; 
       }
       if(k>0)
       {
          br[n]+=k ; 
          if((temp-k)%2==1)
          {
             cr[n] = !ar[n] ; 
          }
       }
       else
       {
          while(idx<=n)
          {
             if(temp%2==1)
             {
                cr[idx]=!ar[idx] ; 
             }
             else
             {
                cr[idx]=ar[idx] ; 
             }
             idx++ ; 
          }
       }
       for(int i=1;i<=n;i++)
       {
          cout << cr[i] ; 
       }
       cout << endl ;
       for(int i=1;i<=n;i++)
       {
         if(i!=1){cout << " " ; }
         cout << br[i] ; 
       }
       cout << endl ;
   }
   return 0 ;
}