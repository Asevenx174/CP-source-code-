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
int main()
{
   debugMode();
   int test ; 
   cin >> test ;
   while(test--)
   {
      map < int , bool > used ; 
      set < int > ase,miss ; 
      int n,k ;
      cin >> n >> k ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         scanf("%d",&x) ; 
         used[x] = true ; 
      }
      int b = 0 ; 
      for (int i = 0; i < n+5 ; ++i)
      {
         if(used[i])
         {
            b = max(b,i) ; 
            ase.insert(i) ; 
         }
         else
         {
            miss.insert(i) ; 
         }
      }
      int prev = -1 ; 
      while(k>0)
      {
        auto it = miss.begin() ; 
        int a = *it ; 
        if(b+1==a){break;}
        int sum = (a+b) ; 
        int add = sum/2 ; 
        if(sum%2==1){add++;}
        if(prev>=0)
        {
           if(prev==add){k=0;break;}
        }
        ase.insert(add) ; 
        b = max(b,add) ; 
        auto lt = miss.find(add) ; 
        if(lt!=miss.end())
        {
           miss.erase(lt) ; 
        } 
        prev = add ; 
        k-- ; 
      }
      int ans = ase.size()+k ; 
      cout << ans << endl ;
   }
   return 0 ;
}