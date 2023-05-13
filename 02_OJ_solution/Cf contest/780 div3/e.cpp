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
const ll maxx = 2000+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx][maxx],br[maxx][maxx],n ;
void calco(int i,int j)
{
    int p = max(0,br[i][j]-1);
    for(int k=1;k<=n;k++)
    {
       br[i][k] = max(0,br[i][k]-1) ; 
       br[k][i] = max(0,br[k][i]-1) ; 
    }
    br[i][j] = p ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int ans = 0 ;
      ms(br,0) ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='0' ? 0 : 1 ; 
            ar[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      for(int i=1;i<=n;i++)
      {
         int r=0,c=0 ; 
         for(int j=1;j<=n;j++)
         {
             r+=ar[i][j] ; 
             c+=ar[j][i] ;
         }
         for(int j=1;j<=n;j++)
         {
             if(ar[i][j]==1)
             {
                br[i][j]+=(r-1)  ; 
             }
             if(ar[j][i]==1)
             {
                br[j][i]+=c  ;
             }
         }
         if(r==0){ans++;}
         if(c==0){ans++;}
      }
      priority_queue < pair < int ,pii > > pq ; 
      for (int i = 0; i < n ; ++i)
      {
         for (int j = 0; j < n ; ++j)
         {
             int temp = br[i+1][j+1] ; 
             if(temp>1)
             {
                pq.push({temp,{i+1,j+1}}) ; 
             }
         }
      }
      while(!pq.empty())
      {
         pair < int , pii > temp = pq.top() ; 
         pq.pop() ;
         pii pp = temp.ss  ;
         if(br[pp.ff][pp.ss]>1)
         {
            calco(pp.ff,pp.ss);
            ans++ ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}