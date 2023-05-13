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
const ll maxx = 25,mod=1e9+7,imax=1e18+10 ;
bool d1[maxx],d2[maxx],col[maxx];
int column[maxx];
int arr[maxx][maxx];
int queen(int row)
{
    if(row>8){return 1 ; }
    ll sum = 0 ;
    for(int i=1;i<9;i++)
    {
        if(arr[row][i]==1 || col[i] || d1[i+row] || d2[10+row-i]){continue;}

        col[i]=true ;
        d1[i+row]=true ;
        d2[10+row-i]=true ;

        sum+=queen(row+1);

        col[i]=false ;
        d1[i+row]=false ;
        d2[10+row-i]=false ;

    }
    return sum ;
}
int main()
{
   int f = 0 ;
   for(int i=1;i<=8;i++)
   {
       string s ;
       cin >> s ;
       int idx = 1,co=0;
       for(auto c : s )
       {
           if(c=='*')
           {
               arr[i][idx]=1 ;
               co++;
           }
           idx++;
       }
       if(co==8){f=1;}
   }
   if(f==1){cout << "0" << endl ; return 0 ; }
   ll ans = queen(1) ;
   cout << ans << endl;
   return 0 ;
}
