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
int srr[maxx],w[maxx] ;
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      string s ;
      cin >> s ;
      int n = s.size() ; 
      int x ;
      cin >> x ;
      int idx = 1 ; 
      for(auto c : s )
      {
         w[idx]=1;
         int y = c=='1' ? 1 : 0 ; 
         srr[idx++]=y ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(srr[i]==1){continue;}
         int p = i+x ; 
         int q = i-x ; 
         if(p<=n)
         {
            //cout << p << endl ;
            w[p]=0;
         }
         if(q>0)
         {
            //cout << q << endl ;
            w[q]=0;
         }
      }
      int ans = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(srr[i]==0){continue;}
         int p = i+x ; 
         int q = i-x ; 
         int f = 0 ; 
         if(p<=n)
         {
            if(w[p]==1){f=1;}
         }
         if(q>0)
         {
            if(w[q]==1){f=1;}
         }
         //cout << q << " " << w[q] << endl ;
         if(f==0){ans=-1;break;}
      }
      if(ans==-1){cout << ans << endl; continue ;}
      for(int i=1;i<=n;i++)
      {
         cout << w[i] ; 
      }
      cout << endl ;
   }
   return 0 ;
}