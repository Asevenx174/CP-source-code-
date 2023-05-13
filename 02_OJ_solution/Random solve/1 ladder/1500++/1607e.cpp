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
      int r,c ;
      cin >> r >> c ; 
      int lx=0,rx=0,ly=0,ry=0 ;
      string s ;
      cin >> s ;
      int p=0,q=0 ; 
      for(auto ch : s )
      {
         if(ch=='L' || ch=='R')
         {
            if(ch=='L'){p--;}else{p++;}
            int a = lx , b = rx ; 
            lx = min(lx,p) ; 
            rx = max(rx,p) ;
            //cout << abs(lx-rx) << " " << c <<  endl ;
            if(abs(lx-rx)>=c)
            {
               lx = a ; 
               rx = b ; 
               break ; 
            }
         }
         else
         {
            if(ch=='D'){q--;}else{q++;}
            int a = ly , b = ry ;
            ly = min(ly,q) ; 
            ry = max(ry,q) ;
            if(abs(ly-ry)>=r)
            {
               ly = a ; 
               ry = b ; 
               break ; 
            }
         }
      } 
      //cout << lx << " " << rx << endl ;
     // cout << ly << " " << ry << endl ;
      int y = c-rx ; 
      int x = ry+1 ; 
      cout << x << " " << y << endl ;
   }
   return 0 ;
}