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
const ll maxx = 1e6+10,mod=1e9+7,imax=1e18+10;
char arr[maxx];
int main()
{
   int f = 1 , len  ;
   map < char ,int > pq ;
   string  s ;
   cin >> s ;
   len = s.size() ;
   for(auto c : s )
   {
       pq[c]++;
   }
   int odd = 0,idx=0;
   char c ;
   for(auto p : pq )
   {
       int x = p.ss ;
       if(p.ss%2==1)
       {
           odd++;
           x--;
           c = p.ff ;
       }
       while(x>0)
       {
           arr[idx]=p.ff ;
           arr[len-idx-1]=p.ff ;
           idx++;
           x-=2;
       }
   }
   if( (len%2==0 && odd!=0) || (len%2==1 && odd!=1))
   {
       cout << "NO SOLUTION" << endl;
       return 0 ;
   }
   if(len%2==1)
   {
       arr[idx]=c ;
   }
   for(int i=0;i<len;i++)
   {
       cout << arr[i] ;
   }
   cout << endl;
   return 0 ;
}
