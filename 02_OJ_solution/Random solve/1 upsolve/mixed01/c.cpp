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
#define pi                 pair < int , pair < int ,int > >

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
const ll maxx = 55 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int t[5][maxx],pl[5][maxx],k ; 
std::vector < pi > v ;
bool com (const pi &a,const pi &b)
{
   if(a.ses==b.ses)
   {
      return a.sef < b.sef ; 
   }
   else
   {
      return a.ses > b.ses ; 
   }
}
bool com1 (const pi &a,const pi &b)
{
   if(a.ff==b.ff)
   {
      return a.ses > b.ses ; 
   }
   else
   {
      return a.ff < b.ff ; 
   }
}
int ir[maxx+10],pr[maxx+10],tr[maxx+10] ; 
int calco(int idx,int time)
{
    std::vector< pi > pq ;
    for(int i=1;i<=idx;i++)
    {
       pq.push_back({tr[i],{ir[i],pr[i]}}) ; 
    }
    sort(pq.begin(),pq.end(),com1);
    map < int ,int > f ; 
    int ans = 0 ; 
    int cost = 0  ;
    for(auto u : pq )
    {
        
       if(time-u.ff<0){break;}
       time-=u.ff ; 
       ans+=(u.ses) ; 
       f[u.sef]++ ; 
       if( f[u.sef]>1 ){cost++;}
    }
    if(cost>k){ return 0 ; }
    return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      v.clear() ; 
      int n,time ;
      cin >> n >> k >> time ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> t[1][i+1] >> t[2][i+1] >> t[3][i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> pl[1][i+1] >> pl[2][i+1] >> pl[3][i+1] ; 
      }
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=3;j++)
         {
            pi temp = {i,{t[j][i],pl[j][i]}} ;
            v.push_back(temp) ; 
         }
      }
      sort(v.begin(),v.end(),com) ; 
      int idx = 1 ; 
      for(auto x : v )
      {
         //cout << x.ff << " " << x.sef << " " << x.ses << endl ;
         ir[idx] = x.ff ; 
         tr[idx] = x.sef ;
         pr[idx] = x.ses ; 
         idx++ ;  
      }
      int ans = 0 ; 
      for(int i=1;i<=n;i++)
      {
         int temp = calco(i,time) ; 
         ans = max(ans,temp) ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}