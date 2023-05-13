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
int ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      int idx = 1 ; 
      std::vector< int > v ;
      int val = 0 ,first=0,last=0; 
      while(idx<n)
      {
         int len = 1 ; 
         while(ar[idx]==ar[idx+1])
         {
            idx++ ; 
            len++ ; 
         }
         if(len>1)
         {
             if(first==0)
             {
                first = idx-len+3 ; 
             }
             else
             {
                last = idx-1 ; 
             }
             v.push_back(len) ; 
             val = len ; 
         }
         idx++ ; 
      }
     // cout << first << " " << last << endl ;
      int op = 0 ,len = val ; 
      if(v.size()==1)
      {
         if(len==2)
         {
            op = 0 ; 
         }
         else if(len==3)
         {
            op = 1 ; 
         }
         else
         {
            op = len-3 ; 
         }
      }
      else if(v.size()>1)
      {
         op = last-first+1 ; 
      }
      cout << op << endl ; 
   }
   return 0 ;
}