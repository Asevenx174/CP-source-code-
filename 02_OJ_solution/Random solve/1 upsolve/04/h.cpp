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
const ll maxx = 25 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
map < int ,char > ic ; 
map < char ,int > ci ;
int ar[maxx+10] ; 
string calco(int b,string m,int len)
{
      int temp = b ; 
      while(temp>0)
      {
         if(ar[temp]>0)
         {
            m[temp-1]=ic[ ar[temp]-1 ] ; break ; 
         }
         temp-- ; 
      }
      string ans = "" ; 
      while(ans.size()<len)
      {
         ans+=m ; 
      }
      return ans ; 
}
int main()
{
   debugMode();
   int idx = 1 ; 
   char cc = '1' ; 
   while(idx<10)
   {
      ic[idx] = cc ; 
      ci[cc] = idx ; 
      idx++ ; 
      cc++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      string n ;
      cin >> n ;
      idx = 1 ; 
      for(auto c : n )
      { 
         ar[idx++]=ci[c] ; 
      }
      int len = n.size() ; 
      int b = len/2 ; 
      while((len%b)!=0){b--;}
      int temp = b ; 
      string m = "" ; 
      for(auto c : n )
      {
         m+=c ; 
         temp-- ; 
         if(temp==0){break;}
      }
      string ans = "" ; 
      while(ans.size()<len)
      {
         ans+=m ; 
      }
      if(ans<=n)
      {
         cout << ans << endl ; continue ; 
      }

      ans = "" ; 
      while(b>0)
      {
         if(len%b==0)
         {
            temp = b ; 
            m = "" ; 
            for(auto c : n )
            {
              m+=c ; 
              temp-- ; 
              if(temp==0){break;}
            }
            //cout << b << " " << m << endl ;
            string pq = calco(b,m,len) ; 
            ans = max(ans,pq) ; 
         }
         b-- ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}