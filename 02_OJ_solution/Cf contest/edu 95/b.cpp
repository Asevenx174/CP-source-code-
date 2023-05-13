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
const ll maxx = 110 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx],n,lr[maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > pos,val ;
      cin >> n ;
      lp(i,1,n){cin >> ar[i] ;}
      lp(i,1,n){cin >> lr[i] ;
      if(lr[i]==0)
      {
         pos.push_back(i) ; 
         val.push_back(ar[i]) ; 
      }
      }
      sort(val.begin(),val.end(),greater<int>()) ; 
      auto it = pos.begin() ; 
      for(auto x : val )
      {
         int idx = *it ; it++ ; 
         ar[idx] = x ; 
      }
      /*int worst = mod ; 
      int idx = n,k=0 ; 
      while(idx>0)
      {
         worst = min(worst,ar[idx]) ; 
         if(worst<0)
         {
            k = idx ; break ; 
         }
         idx-- ; 
      }
      cout << k << endl ;*/
      lp(i,1,n)
      {
         if(i!=1){cout << " " ; }
         cout << ar[i] ; 
      }
      cout << endl ;
   }
   return 0 ;
}