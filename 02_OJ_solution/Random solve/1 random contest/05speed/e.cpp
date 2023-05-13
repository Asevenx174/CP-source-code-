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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      string s ;
      cin >> s ;
      int a=0,b=0,c=0,idx=1 ; 
      for(auto ch : s )
      {
         if(ch=='-'){a++;} else if (ch=='<') { b++; } else{c++;}
         int temp = 1 ;
         if(ch=='<'){temp=2;}
         else if(ch=='>')
         {
            temp=3 ; 
         } 
         ar[idx++] = temp ; 
      }
      if(s=="--")
      {
         cout << "2" << endl ; continue ; 
      }
      if(b==0 || c==0 || a==n || b==n || c==n) { cout << n << endl ; continue ; }
      int ans = 0 ; 
      for(int i=1;i<n;i++)
      {
         if(ar[i]==1){ans+=2;}
         if(ar[i]==1 && ar[i-1]==1)
         {
            ans-- ; 
         }
      } 
      if(ar[n]==1)
      {
         if(ar[n-1]!=1)
         {
            ans++ ; 
         }
         if(ar[1]!=1){ans++;}
      }
      cout << ans << endl ;
   }
   return 0 ;
}