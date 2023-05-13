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
   deque < pii > dq ; 
   ll q ;
   cin >> q ;
   while(q--)
   {
      ll idx,x,c ; 
      cin >> idx ; 
      if(idx==1)
      {
        cin >> x >> c ; 
        dq.push_back({x,c});
      }
      else
      {
        cin >> c ; 
        ll sum = 0 ; 
        while(!dq.empty() && c>0)
        {
           pii p = dq.front() ; 
           dq.pop_front() ; 
           ll val = p.ff ;
           ll q = p.ss ; 
           ll sub = min(c,q) ; 
           q-=sub ; 
           sum+=(sub*val) ; 
           c-=sub ;
           if(q>0)
           {
             dq.push_front({val,q}) ; 
           }
        }
        cout << sum << endl ; 
      }
   }
   return 0 ;
}