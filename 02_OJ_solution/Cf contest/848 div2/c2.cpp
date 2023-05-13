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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 4e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
std::vector < ll > v ;
void precom()
{
   v.push_back(0) ; 
   for(int i=1;i<=632;i++)
   {
      int temp = i*i ; 
      v.push_back(temp) ; 
   }
}
ll pq[maxx+10] ; 
void solve()
{ 
   cin >> n ;
   for (int i = 0; i <=2*n ; ++i)
   {
      pq[i] = 0 ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      scanf("%d",&ar[i+1]) ;  
   }
   pq[0]++ ; 
   ll pre = 0,ans=0,best=0 ;  
   for (int i = 0; i < n ; ++i)
   {
      ll x = ar[i+1] ; 
      pre = pre^x ;  
      for(auto r:v)
      {  
         ll q = r^pre ; 
         if(q>best){continue;}
         ans+=pq[q] ; 
      }
      pq[pre]++ ; 
      best = max(best,pre) ; 
   }
   ll temp = (n*(n+qq)) ; 
   temp = temp/tt ; 
   temp = temp-(ll)ans ;
   printf("%I64d\n",temp) ;   
}
int main()
{
   debugMode();
   precom() ; 
  // cout << v.size() << endl ;
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}