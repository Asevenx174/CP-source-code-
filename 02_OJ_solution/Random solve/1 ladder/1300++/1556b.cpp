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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int arr[maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > v[5] ;
      int n,a=0,b=0;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         x = x%2 ; 
         if(x==0){a++;}else{b++;}
         v[x].push_back(i+1) ; 
         arr[i] = x ; 
      }
      int p = v[0].size() ; 
      int q = v[1].size() ; 
      int f = 1 ; 
      int d = n%2==0 ? 0 : 1 ; 
      if(abs(p-q)!=d){f=0;}
      if(!f){cout << "-1" << endl; continue ;}

      int x = (n+1)/2 ;
      ll ans = imax ;  
      if(x==a)
      {
         //010101..  
         auto it = v[0].begin() ; 
         auto lt = v[1].begin() ; 
         ll temp = 0 ; 
         for(int i=1;i<=n;i+=2)
         {
            ll z = 0 ; 
            z = abs(i-*it) ; 
            it++ ; 
            temp+=z ; 
         }
         ans = min(ans,temp) ; 
      }

      if(x==b)
      {
         //1010101...  
         auto it = v[1].begin() ; 
         auto lt = v[0].begin() ; 
         ll  temp = 0 ; 
         for(int i=1;i<=n;i+=2)
         {
            ll z = 0 ; 
            z = abs(i-*it) ; 
            it++ ; 
            temp+=z ; 
         }
         ans = min(ans,temp) ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}