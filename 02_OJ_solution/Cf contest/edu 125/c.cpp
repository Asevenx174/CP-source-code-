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
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int arr[maxx],op,idx,d,n,temp; 
int calco()
{
      temp=0;
      int f = 0 ; 
      while(idx+1<=n)
      {
         if( !(arr[idx]==1 && arr[idx+1]==0) )
         {
            op++;
            d+=2 ;
            idx+=2;
         } 
         else{ idx+=2 ; temp=2; f = 1 ; break;}
      }
      return f ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ; 
      string s ;
      cin >> s ;
      op,idx=1,d=0 ;
      while(idx<=n)
      {
         int x = s[idx-1] == '(' ? 0 : 1 ; 
         arr[idx++] = x ; 
      }
      op=0,d=0,idx=1 ; 
      while(calco())
      {
         //cout << d << endl ;
         int q = 0 ;
         while(idx<=n)
         {
            temp++ ; 
            if(arr[idx++]==1)
            {
               op++ ; 
               q=1 ; 
               break ; 
            }
         }
         if(q==1)
         {
            d+=temp ; 
         }
         else{break;}
      }
      cout << op << " " << (n-d) << endl ;
   }
   return 0 ;
}