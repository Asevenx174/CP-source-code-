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
ll ar[maxx+10],n,pr[maxx+10],temp[maxx+10],kr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector < ll > pos ;
      ll sum = 0,ans=0,best=0 ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         sum+=ar[i+1] ; 
         pr[i+1] = sum ; 
         if(sum==zz)
         { 
            best++ ; 
         }
         temp[i+1] = best ; 
         if(ar[i+1]==zz)
         {
            pos.push_back(i+1) ; 
         }
      }
      pos.push_back(n+1) ; 
      for(ll i=1;i<pos.size();i++)
      {
         ll l = pos[i-1] ; 
         ll r = pos[i]-qq ; 
         map < ll , ll > pq ; 
         ll add = 0 ; 
         while(l<=r)
         {
            ll x = pr[l] ; 
            pq[x]++ ; 
            add = max(add,pq[x]) ; 
            l++ ; 
         }
         kr[i-1] = add ; 
      }
      ans = best ; 
      sum = 0 ; 
      ll last = pos.size()-2LL ; 
      while(last>=zz)
      {
         sum+=kr[last] ; 
         kr[last] = sum ; 
         last-- ; 
      }
      for(ll i=0;i+qq<pos.size();i++)
      {
         ll idx = pos[i] ; 
         ll add = temp[idx-1]+kr[i] ; 
         ans = max(ans,add) ; 
      }
      cout << ans << endl ;
   } 
   return 0 ;
}