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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int sr[maxx+10],n ; 
void sett(int idx)
{
   for(int i=1;i<24;i++)
   {   
      int f = 1 ; 
      int l = max(0,idx-3) ; 
      int r = min(n,idx+3) ; 
      for(int j=l;j<=r;j++)
      {
          if(i==sr[j]){f=0;}
      }
      if(f==1)
      {
         sr[idx]=i ; 
         return  ; 
      }
   }
}
int main()
{
   debugMode();
   map < char ,int > ci ; 
   char cc = 'a' ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      ci[cc++]=idx++;
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      string s ;
      cin >> s ;
      idx = 1 ;
      n = s.size() ; 
      for(auto c : s )
      {
         int x = ci[c] ; 
         sr[idx++] = x ; 
      }
      sr[0]=-1 ; 
      sr[n+1]=-1 ; 
      int ans = 0 ; 
      for(int i=3;i<=n;i++)
      {
         if(sr[i]==sr[i-2])
         {
            sett(i) ; 
            ans++ ; 
         }
         if(sr[i-1]==sr[i-2])
         {
            sett(i-1);
            ans++ ; 
         }
      }
      for(int i=2;i<=n;i++)
      {
         if(sr[i]==sr[i-1])
         {
            sett(i) ; 
            ans++ ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}