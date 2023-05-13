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
ll ar[maxx+10] ; 
int l[maxx+10],r[maxx+10] ;  
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,f=0;
      cin >> n ;
      for(int i=1;i<=n;i++)
      {
         int x ; 
         scanf("%d",&x) ; 
         ar[i] = x ;  
         if(i>1 && min(ar[i],ar[i-1])>zz ){f=1;}
      }
      if(f==qq)
      {
         printf("NO\n") ; 
         continue ;  
      }
      stack < pii > stk,stk2 ; 
      ar[0] = mod ; 
      ar[n+1] = mod ; 
      for(int i=1;i<=n+1;i++)
      {
         int next = ar[i] ; 
         if(stk.empty())
         {
            stk.push( {next,i} ) ; continue ; 
         }
         while(!stk.empty() && stk.top().ff<next)
         { 
            int pidx = stk.top().ss ; 
            r[pidx] = i ; 
            stk.pop() ; 
         }
         stk.push( {next,i} ) ; 
      }
      

      for(int i=n;i>=0;i--)
      {
         int next = ar[i] ; 
         if(stk2.empty())
         {
            stk2.push( {next,i} ) ; continue ; 
         }
         while(!stk2.empty() && stk2.top().ff<next)
         { 
            int pidx = stk2.top().ss ; 
            l[pidx] = i ;
            //cout << pidx << " " << i << endl ; 
            stk2.pop() ; 
         }
         stk2.push( {next,i} ) ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(ar[i]>0)
         {
            ll sum = 0 ; 
            ll sub = 0 ; 
            ll a = l[i] ; 
            ll b = r[i] ; 
            //cout << a << " " << i << " " << b << endl ;
            // a[..]i[..]b
            ll y = b-1 ; 
            while(y>i)
            {
               sum+=ar[y] ; 
               sub = min(sub,sum) ; 
               y-- ; 
            }

            if(sum-sub>zz){f=1;}
            sub = 0 ; 
            ll x = a+1 ; 
            sum = 0 ; 
            while(x<i)
            {
               sum+=ar[x] ; 
               sub = min(sub,sum) ; 
               x++ ; 
            }
            if(sum-sub>zz){f=1;}
            i = b ;  
         }
         if(f==1){break;}
      }
      if(f==qq)
      {
         printf("NO\n") ; 
      }
      else
      {
         printf("YES\n") ; 
      }
   }
   return 0 ;
}