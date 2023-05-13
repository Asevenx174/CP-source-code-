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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
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
int pq[maxx+10] ,ar[maxx+10]; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(pq,0) ; 
      int n,s ;
      cin >> n >> s ;
      int sum = 0 ; 
      for(int i=1;i<=n;i++)
      {
         cin >> ar[i]  ; 
         sum+=ar[i] ; 
      }
      int temp = n , ans = 0  ;
      while(temp>0)
      {
         ans+=ar[temp] ; 
         if(pq[ans]==0)
         {
            pq[ans] = temp ; 
         }
         temp-- ; 
      }
      pq[0] = n+1 ; 
      int pre = 0  ; 
      int res = mod ; 
      for(int i=0;i<=n;i++)
      {
         pre+=ar[i] ; 
         int need = sum-pre-s ; 
         if(pq[need]!=0)
         {
            int j = pq[need] ; 
            //cout << i << " " << j << endl ;
            int temp = i+(n-j+1) ; 
            if(i<j)
            {
               res = min(res,temp) ; 
            }
         }
      }
      if(res==mod){res=-1;}
      cout << res << endl ;
   }
   return 0 ;
}