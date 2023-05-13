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
std::vector< int > g[maxx];
int n ,lvl[maxx] ;
bool used[maxx] ; 
void dfs(int u,int l)
{
   lvl[l]++ ; 
   used[u] = true ;
   for(auto x : g[u] )
   {
      if(used[x]){continue;}
      dfs(x,l+1) ; 
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      for (int i = 0; i <= n ; ++i)
      {
         g[i].clear() ; 
         lvl[i] = 0 ; 
         used[i] = false ;
      }

      for (int i = 2 ; i <=n; ++i)
      {
         int p ; 
         cin >> p ;
         g[i].push_back(p) ; 
         g[p].push_back(i) ; 
      }
      dfs(1,1) ; 
      priority_queue < int > pq,q ; 
      int t = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(lvl[i]>0)
         {
            q.push(lvl[i]) ; 
            t++ ; 
         }
      }
      for(int i=t;i>0;i--)
      {
         if(!q.empty())
         {
            int u = q.top() ; 
            q.pop() ; 
            int sub = min(u,i) ; 
            u-=sub ; 
            if(u>0){pq.push(u);} 
         }
         else{break;}
      }
      int sub = 0 ; 
      while(!pq.empty())
      {
         int u = pq.top() ; 
         pq.pop() ; 
         u = max(0,u-sub) ; 
         if(u>0)
         {
           u-- ; 
           if(u>0){pq.push(u);} 
           sub++ ; 
           t++ ; 
         }
      }
      cout << t << endl ;
   }
   return 0 ;
}