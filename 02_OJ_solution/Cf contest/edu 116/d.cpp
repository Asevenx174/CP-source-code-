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
int val,aa  ; 
map < char ,int > ci ; 
map < int ,char > ic ; 
int rev(int n)
{
   int len = 1 ; 
   string add = "" ; 
   while(n>9)
   {
      int x = n%10 ; 
      add+=ic[x] ;
      n = n/10 ; 
      len++ ; 
   }
   add+=ic[n] ;
   swap(add[0],add[len-1]) ; 
   int sum = 0 , mul=1 ; 
   for(auto c : add )
   {
      int temp = ci[c]*mul ; 
      mul = mul*10 ; 
      sum+=temp ; 
   }
   return sum ; 
}

int calco(int x,int idx)
{
   //cout << x << " " << idx << endl ;
   if(x==val){
      cout << x <<  " " << idx << endl ;
      return idx;}
   if(x>val)
   {
      if(x>9 && x%10!=0)
      {
         int r = rev(x) ; 
         if(r==val){return idx+1 ;}
      }
      return mod ; 
   }
   int ans = calco(x*aa,idx+1) ; 
   if(x>9 && x%10!=0)
   {
       int r = rev(x) ; 
       if(r==val){return idx+1;}
       int temp = calco(r*aa,idx+2) ; 
       ans = min(ans,temp) ; 
   }
   return ans ; 
}
int main()
{
   debugMode() ; 
   char c = '1' ; 
   int idx = 1 ; 
   while(idx<10)
   {
      ci[c] = idx ; 
      ic[idx] = c ; 
      idx++;
      c++;
   }
   int a,n ;
   cin >> a >> n ; 
   val = n ; 
   aa = a ; 
   ll ans = calco(1,0) ; 
   cout << ans << endl ;
   return 0 ; 
}