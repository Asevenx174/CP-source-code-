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
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds ;

using namespace std ;
typedef tree < int , null_type , less <int> , rb_tree_tag , tree_order_statistics_node_update > ordered_set ;

int main()
{
   ordered_set os ;
   int n,k ;
   cin >> n >> k ;
   for(int i=1;i<=n;i++)
   {
       os.insert(i);
   }
   int s = k+1 ;
   if(s>n)
   {
       s = s%n;
   }
   int idx = 0,temp=n;
   while(n--)
   {
     temp--;
     if(idx!=0){cout << " " ;}
     idx = 1 ;
     auto it = os.find_by_order(s-1) ;
     cout << *it ;
     if(temp==0){break;}
     s+=k ;
     if(s>n)
     {
        s = s%n;
       if(s==0){s=n;}
     }
     os.erase(it);
   }
   cout << endl;
   return 0 ;
}
