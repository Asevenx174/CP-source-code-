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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int arr[maxx][maxx],brr[maxx][maxx]; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(brr,0) ; 
      int n,m ;
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ; 
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='1' ? 1 : 0 ; 
            arr[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      if(arr[1][1]==1){cout << "-1" << endl ; continue ;  }
      std::vector< pair < pii ,pii > > ans ;
      for(int i=n;i>0;i--)
      {
         for(int j=m;j>0;j--)
         {
            int x = arr[i][j] ; 
            if(j==1)
            {
               if(arr[i][j]!=brr[i][j])
               {
                  if(x==0)
                  {
                      brr[i][j] = 0 ; 
                      ans.push_back({{i,j},{i,j}}) ;
                  }
                  else
                  {
                      brr[i][j]=1;
                      brr[i-1][j]=0;
                      ans.push_back({{i-1,j},{i,j}}) ;
                  }
               }
            }
            else
            {
               if(arr[i][j]!=brr[i][j])
               {
                  if(x==0)
                  {
                      brr[i][j] = 0 ; 
                      ans.push_back({{i,j},{i,j}}) ; 
                  }
                  else
                  {
                      brr[i][j] = 1 ; 
                      brr[i][j-1] = 0 ; 
                      ans.push_back({{i,j-1},{i,j}}) ;
                  }
               }
            }
         }
      }
      cout << ans.size() << endl ;
      for(auto p : ans )
      {
         pii a = p.ff ; 
         pii b = p.ss ; 
         cout << a.ff << " " << a.ss << " " << b.ff << " " << b.ss << endl ;
      }
   }
   return 0 ;
}