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
const ll maxx = 3010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int psb[maxx],mi[maxx],pl[maxx]; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      string s ;
      cin >> s ;
      int pre=0,cur=0 ;
      int idx = 1 , sum = 1 ; 
      char p ; 
      int a=0,b=0 ;
      for(auto c : s)
      {
         if(c=='-'){a++;}else{b++;}
         mi[idx] = a ; 
         pl[idx] = b ; 
         if(idx==1){idx=2;p=c;continue;}
         if(p==c && p=='-')
         {
            sum++ ; 
         }
         else
         {
            pre+=(sum/2) ; 
            sum = 1 ;
         }
         int temp = pre+sum/2 ;  
         p = c ; 
         psb[idx] = temp ; 
         idx++ ;
      }
      int ans = 0 ; 
      for(int i=1;i<n;i++)
      {
         for(int j=i+1;j<=n;j++)
         {
            int a = mi[j]-mi[i-1];
            int b = pl[j]-pl[i-1];
            int h = psb[j]-psb[i-1] ;
            if(psb[i]!=psb[i-1]){h--;}
            if(a==b){ans++;continue;}
            if(b>a){continue;}
            int temp = a-b ; 
            if(temp%3!=0){continue;}
            int need = temp/3 ; 
            if(h>=need){ans++;}
         }
      } 
      cout << ans << endl ;
   }
   return 0 ;
}