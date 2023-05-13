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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
bool valid(int k)
{
   multiset < int > s ; 
   for (int i = 0; i < n ; ++i)
   {
      s.insert(ar[i+1]) ; 
   }
   int d = 0 ; 
   for(int i=1;i<=k;i++)
   {
      if(s.empty()){return false;}
      if(i>1)
      {
         int temp = k-i+1 ; 
         int x = max(0,temp-d) ; 
         auto it = s.upper_bound(x) ;
         while(it!=s.begin())
         {
            if(*it<=x){break;}
            it-- ; 
         }
         if(it!=s.end())
         {
            int add = *it+d ; 
            s.erase(it) ; 
            s.insert(add) ; 
         } 
      }
      d = k-i+1 ; 
      auto it = s.upper_bound(d) ; 
      if(it==s.begin()){return false;}
      it-- ; 
      s.erase(it) ; 
      d = k-i+1 ; 
   }
   return true ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      int k = n ; 
      int ans = 0 ; 
      while(k>0)
      {
         if(valid(k))
         {
            ans = k ; 
            break ; 
         }
         k-- ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}