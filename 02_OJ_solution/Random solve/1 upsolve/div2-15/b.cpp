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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using myset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
typedef tree<int ,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>os;
int main()
{
   debugMode();
   
      os r,c ; 
      int n,q ;
      cin >> n >> q ;
      for (int i = 0; i < q ; ++i)
      {
         int t ;
         cin >> t ; 
         if(t==2)
         {
            int x,y ;
            cin >> x >> y ; 
            r.erase(r.find(x)) ;
            c.erase(c.find(y)) ; 
            continue ; 
         }
         else if(t==1)
         {
            int x,y ;
            cin >> x >> y ;
            r.insert(x) ; 
            c.insert(y) ; 
            continue ; 
         }
         int x1,y1,x2,y2,a,b ;
         cin >> x1 >> y1 >> x2 >> y2 ; 
         b = r.order_of_key(x2+1) ; 
         a = r.order_of_key(x1) ; 
         int len = b-a+1 ; 
         b = c.order_of_key(y2+1) ; 
         a = c.order_of_key(y1) ; 
         int temp = b-a+1 ; 
         if(len==(x2-x1+1) || (temp==(y2-y1+1)) )
         {
            cout << "Yes" << endl ;
         } 
         else
         {
            cout << "No" << endl ;
         }
      }
   return 0 ;
}