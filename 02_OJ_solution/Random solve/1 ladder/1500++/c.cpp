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
ll n,ar[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      map < int ,int > pq ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
      }
      ll i=n,j=n,ans=1,g=0; 
      
      while(min(i,j)>0)
      {
         int x = ar[i] ,y = br[j] ; 
         int oc = 1 ; 
         while( br[j]==br[j-1] && j>1 )
         {
            oc++ ; 
            j-- ; 
         }
         pq[y]+=oc ; 
         if(oc==1)
         {
            if(x==y)
            {
               pq[y]-- ; 
            }
            else
            {
               if(pq[x]==0)
               {
                  ans = 0 ; 
                  break ;
               }
               else
               {
                  pq[x]-- ; 
               }
            }
         }
         else
         {
            if(pq[x]==0)
            {
               ans = 0 ; 
               break ; 
            }
            else
            {
               pq[x]-- ; 
            }
         }
         i--;
         j--;
      }
      while(i>0)
      {
         int x = ar[i] ; 
         if(pq[x]==0)
         {
            ans = 0 ; 
            break ; 
         }
         else
         {
            pq[x]-- ; 
         }
         i--;
      }
      if(ans==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ; 
      }
   }
   return 0 ;
}