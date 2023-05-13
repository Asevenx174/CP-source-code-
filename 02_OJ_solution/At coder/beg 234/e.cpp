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
const ll maxx = 18 ,mod=1e17+5,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll getlen(ll x)
{
   ll d = 1 ;
   while(x>9)
   {
      d++ ; 
      x = x/10LL ; 
   }
   return d ; 
}
int main()
{
   debugMode();
   set < ll > ans ;  
   for(int i=1;i<10;i++)
   {
      for(int d=-9;d<=8;d++)
      {
         int j=i ;
         if(d==0)
         {
            ll temp=18,sum=0,idx=1; 
            while(temp--)
            {
               sum+=(i*idx) ; 
               ans.insert(sum) ; 
               idx = idx*10LL ; 
            }
            continue ; 
         }
         
         std::vector < ll > k ;
         ll sum=0,idx=1 ; 
         while(j>=0 && j<10)
         {
            k.push_back(j) ;
            j+=d ;   
         }
         
         //cout << i << " " << k.size() << endl ;
         for(int p=0;p<k.size();p++)
         {
            ll last = p,sum=0,idx=1 ; 
            while(last>=0)
            {
               ll x = k[last] ; 
               sum+=(x*idx) ; 
               last--;
               idx=idx*10LL ; 
            }
            //cout << sum << endl ;
            ans.insert(sum) ; 
         }
      }
   }
   ll pq ; 
   cin >> pq ; 
   auto it = ans.lower_bound(pq) ;
   cout << *it << endl ; 
   for(auto x : ans )
   {
     /// cout << x << endl ;
   }
   return 0 ;
}