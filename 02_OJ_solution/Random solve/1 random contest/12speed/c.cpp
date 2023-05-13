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
      int p1=0;
      int p0=0;
      for(auto c : a )
      {
         int x = c=='0' ? 0 : 1 ; 
         ar[idx++] = x ; 
         p+=x ; 
         if(x==0){co++;p0=idx-1;}else{ko++;p1=idx-1;}
      }
      idx = 1 ; 
      int f1=0,f2=0 ;  
      for(auto c : b )
      {
         int x = c=='0' ? 0 : 1 ; 
         br[idx] = x ; 
         if( (ar[idx]^br[idx])==0 )
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
      if(min(f1,f2)==1)
      {
         cout << "NO" << endl ; continue ; 
      }
      std::vector < pii > ans ;
      if(f1==1)
      {
         if(ko%2==1)
         {
            if(ko==1){cout << "NO" << endl ; continue ;}
            ar[p1] = 0 ; 
            ans.push_back({p1,p1}) ; 
         }
         cout << "YES" << endl ; 
         for(int i=1;i<=n;i++)
         {
            if(ar[i]==1)
            {
               ans.push_back({i,i}) ; 
            }
         }
         cout << ans.size() << endl ; 
         for(auto x : ans )
         {
            cout << x.ff << " " << x.ss << endl ;
         }
      }
      else
      {
         if(co%2==1)
         {
            if(co==1){cout << "NO" << endl ; continue ;}
            ar[p0] = 0 ; 
            ans.push_back({p0,p0}) ; 
         }
         cout << "YES" << endl ; 
         for(int i=1;i<=n;i++)
         {
            if(ar[i]==0)
            {
               ans.push_back({i,i}) ; 
            }
         }
         ans.push_back({1,n})  ; 
         cout << ans.size() << endl ; 
         for(auto x : ans )
         {
            cout << x.ff << " " << x.ss << endl ;
         }
      }
   }
   return 0 ;
}