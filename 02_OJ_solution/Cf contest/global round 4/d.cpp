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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1005,mod=2000,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
vector < int > prime ;
ll arr[mod+10];
void seive(ll lim)
{
    for(int i=4;i<=lim;i+=2){arr[i]=1;}
    for(int i=3;(ll)i*i<=lim;i+=2)
    {
        if(!arr[i])
        {
            for(int j=i+i;j<=lim;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    for(int i=2;i<=lim;i++)
    {
        if(!arr[i])
        {
            prime.push_back(i);
        }
    }
}
vector < int > g[maxx+10] ; 
bool used[maxx][maxx] ; 
int main()
{
   debugMode();
   seive(mod) ;
   int n,add=0,temp=0 ;
   cin >> n ;
   if(n%2==1)
   {
      add=2 ; 
      g[n].push_back(n-1) ; 
      g[n-1].push_back(n) ; 
      g[n-1].push_back(n-2) ; 
      g[n-2].push_back(n-1) ; 
      n-=3 ; 
      temp = 3 ; 
   } 
   auto it = lower_bound(prime.begin(),prime.end(),n) ;
   int e = *it ; 
   for(int i=1;i<n;i++)
   {
      g[i].push_back(i+1) ; 
      g[i+1].push_back(i) ;
      used[i][i+1] = true ; 
      used[i+1][i] = true ; 
   }
   g[1].push_back(n) ; 
   g[n].push_back(1) ; 
   used[1][n] = true ; 
   used[n][1] = true ; 
   e-=(n) ; 
   for(int i=1;i<n;i++)
   {
      if(g[i].size()!=2){continue;}
      for(int j=i+1;j<=n;j++)
      {
         if(g[j].size()!=2){continue;}
         if(e==0){break;}
         if(!used[i][j])
         {
            used[i][j] = true ;
            used[j][i] = true ; 
            e-- ; 
            g[i].push_back(j) ; 
            g[j].push_back(i) ; 
            break ; 
         }
      }
      if(e==0){break;}
   }

   int ans = add  ;
   if(n>0)
   {
      ans+=(*it) ; 
   }
   cout << ans << endl ; 
   for(int i=1;i<=n+temp;i++)
   {
      for(auto x : g[i] )
      {
         if(x<i){continue;}
         cout << i << " " << x << endl ;
      }
   }
   return 0 ;
}