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
int t[maxx],a[maxx],m[maxx],best=0,c,d,n; 
void calco(int l,int r)
{
   if(l>r){return ;}
   //cout << l << " ?? " << r << endl ;
   int sum = t[r]-t[l-1] ; 
   //cout << l << " " << r << " " << sum << endl ;
   if(sum>best)
   {
      //cout << sum << " " << l << " " << r << endl ;
      best = sum ; 
      c = l-1 ; 
      d = n-r ; 
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(t,0) ; 
      std::vector < int > z,neg ;
      z.push_back(0) ; 
      cin >> n ;
      int pre = 0,co=0  ;
      for (int i = 0; i < n ; ++i)
      {
         c = 0 ; 
         d = n ; 
         cin >> a[i+1] ; 
         if(a[i+1]==0)
         {
            z.push_back(i+1) ; 
         }
         else if(a[i+1]<0)
         {
            neg.push_back(i+1) ; 
            co++ ; 
         }
         if(a[i+1]==2 || a[i+1]==-2){pre++;}
         t[i+1] = pre ;
         m[i+1] = co ; 
      }
      z.push_back(n+1) ; 
      best = 0 ; 
      c = 0 ; 
      d = n ; 
      for(int i=1;i<z.size();i++)
      {
         int l = z[i-1]+1 ;
         int r = z[i]-1 ; 
         int f = m[r]-m[l-1] ; 
        // cout << l << " " << r << endl ;
         if(f%2==1)
         {
            auto it = lower_bound(neg.begin(),neg.end(),l) ; 
            auto lt = upper_bound(neg.begin(),neg.end(),r) ; 
            lt-- ; 
            int idx = *it  ;
            calco(l,idx-1);
            calco(idx+1,r) ;
            idx = *lt ;
            calco(l,idx-1);
            calco(idx+1,r) ; 
         }
         else{calco(l,r);}
      }
      cout << c << " " << d << endl ;
   }
   return 0 ;
}