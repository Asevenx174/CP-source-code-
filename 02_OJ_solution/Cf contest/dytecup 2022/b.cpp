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
int ar[maxx+10],br[maxx+10],n ; 
int main()
{
   debugMode();
   int test ; 
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      string a,b ;
      cin >> a >> b ; 
      a = '$'+a ; 
      b = '$'+b ;
      for (int i = 0; i < n+1 ; ++i)
      {
         int x = a[i]=='0' ? 0 : 1 ; 
         ar[i] = x ; 
      }
      int p = 0 ; 
      int q = 0 ; 
      for (int i = 0; i < n+1 ; ++i)
      {
         int x = b[i]=='0' ? 0 : 1 ; 
         br[i] = x ; 
         if(i>0)
         {
            if(ar[i]^br[i]){p=1;}else{q=1;}
         }
      }
      if(n==1)
      {
         if(ar[1]==0 && br[1]==0)
         {
            cout << "YES" << endl ;
            cout << "0" << endl ;
         }
         else if(ar[1]==1 && br[1]==0)
         {
            cout << "YES" << endl ;
            cout << "1" << endl ;
            cout << "1 1" << endl ;
         }
         else
         {
            cout << "NO" << endl ;
         }
         continue ; 
      }
      if(p && q)
      {
         cout << "NO" << endl ; continue ; 
      }
      int val = br[1] ; 
      std::vector < pii > ans ;
      for(int i=1;i<=n;i++)
      {
         if(ar[i]==0)
         {
            ans.push_back({i,i}) ; 
            if(i>1){val=!val;}
         }
      }
      if(val==0)
      {
         ans.push_back({1,n}) ; 
      }
      else
      {
         ans.push_back({1,1}) ; 
         ans.push_back({2,n}) ; 
      }
      cout << "YES" << endl ; 
      cout << ans.size() << endl ;
      for(auto p : ans )
      {
         cout << p.ff << " " << p.ss << endl ;
      }
   }
   return 0 ;
}