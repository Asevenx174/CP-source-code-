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
int ar[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,co=0,ko=0 ;
      cin >> n ; 
      string a,b ;
      cin >> a >> b ; 
      int idx = 1 ; 
      int p = 0 ;
      int q = 0 ; 
      for(auto c : a )
      {
         int x = c=='0' ? 0 : 1 ; 
         ar[idx++] = x ; 
         p+=x ; 
         if(x==0){co++;}else{ko++;}
      }
      idx = 1 ; 
      int f1=0,f2=0 ;  
      for(auto c : b )
      {
         int x = c=='0' ? 0 : 1 ; 
         br[idx] = x ; 
         if( ar[idx]^br[idx] )
         {
            f1 = 1 ; 
         }
         else
         {
            f2 = 1 ; 
         }
         q+=x ; 
         idx++ ; 
      }
      if(max(p,q)==0)
      {
         cout << "YES" << endl ;
         cout << "0" << endl ; 
         continue ; 
      }
      else if(min(p,q)==n)
      {
         cout << "YES" << endl ;
         cout << "2" << endl ;
         cout << "1 1" << endl ;
         cout << "2 " << n << endl ;
         continue ; 
      }
      if(f2==1 && f1==1)
      {
         cout << "NO" << endl ;
         continue ; 
      }
      int val = f2==1 ? 1 : 0 ; 
      if(f1==1 && co%2==1)
      {
         cout << "NO" << endl ; 
         continue ; 
      }
      if(f2==1 && ko%2==1)
      {
         cout << "NO" << endl ; 
         continue ; 
      }
      idx = 1 ; 
      std::vector < pii > ans ;
      while(idx<=n)
      {
         if(ar[idx]!=val){ idx++ ; continue;}
         int l = idx ; 
         int r = l ; 
         while(ar[r+1]==val && r+1<=n)
         {
            r++ ; 
         }
         ans.push_back({l,r}) ; 
         idx++ ; 
      }
      cout << "YES" << endl ;
      int all = ans.size() ; 
      //cout << all << endl ;
      for(auto p : ans )
      {
         cout << p.ff << " " << p.ss << endl ;
      }
   }
   return 0 ;
}