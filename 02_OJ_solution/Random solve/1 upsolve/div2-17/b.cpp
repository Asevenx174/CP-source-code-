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
int f[maxx+10] ; 
set < int > s ; 
int n,d,dig=0 ; 
int main()
{
   debugMode();
   priority_queue < int , vector < int > , greater < int > > pq ; 
   cin >> n >> d ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      if(x==d){continue;}
      pq.push(x) ; 
   }
   int ans = 1 ; 
   while(!pq.empty())
   {
      int x = pq.top() ; pq.pop() ; 
      if(x==d){continue;}
      int temp = x ; 
      int f = 1 ; 
      while(temp>0 && !pq.empty())
      {
         if(pq.top()!=x){f=0;break;}
         pq.pop() ; 
         temp-- ; 
      }
      if(temp!=0){f=0;}
      if(!f){ans=0;break;}
      pq.push(x+1) ; 
   }
   if(ans)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}