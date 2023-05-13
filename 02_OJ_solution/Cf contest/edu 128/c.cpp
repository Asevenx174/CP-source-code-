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
int ar[maxx+10],lr[maxx+10],rr[maxx+10],zero=0,len ; 
bool valid(int lim)
{
   
   int d = zero-lim ; 
   int cost = mod ; 
   lp(i,0,d)
   {
       int l = i ;
       int r = d-l ; 
       int temp = lr[l]+rr[r] ; 
       cost = min(cost,temp) ; 
   } 
   if(cost<=lim){return true ;}
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      zero = 0 ; 
      
      memset(lr, maxx , sizeof(lr)); 
      memset(rr, maxx , sizeof(rr)); 
      
      lr[0] = 0 ; 
      rr[0] = 0 ;
      string s ;
      cin >> s ;
      len = s.size() ;  
      int idx = 1,sum=0,z=0 ;
      for(auto c : s )
      {
         if(c=='1'){sum++;}else{z++;zero++;}
         lr[z]=min(lr[z],sum) ; 
         idx++ ; 
      } 
      string temp = s ; 
      reverse(temp.begin(),temp.end()) ; 

      idx = 1,sum=0,z=0 ;
      for(auto c : temp )
      {
         if(c=='1'){sum++;}else{z++;}
         rr[z]=min(rr[z],sum) ; 
         idx++ ; 
      } 
      int l=0,r=zero,ans=0 ; 
      while(l<=r)
      {
         int m = (l+r)/2 ; 
         if(valid(m))
         {
            ans = m ; 
            r = m-1 ;  
         }
         else
         {
            l = m+1 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}