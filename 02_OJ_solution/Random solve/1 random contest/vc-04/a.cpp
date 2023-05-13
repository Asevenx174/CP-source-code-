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
int siz = mod ; 
string res = "-",pa,pb ; 
int ar[maxx+10],br[maxx+10],n,m,lr[maxx+10],rr[maxx+10] ; 
map < int , char > ic ; 
map < char ,int > ci ; 
string send(int l,int r)
{
   string temp = "" ; 
   for(int i=1;i<=m;i++)
   {
      if(l<=i && i<=r){continue;}
      temp+=pb[i-1] ; 
   }
   return temp ;
}
bool valid(int len,int pos)
{
   if(len==m){return true;}
   int a = 0 ;
   int b = 0 ; 
   for(int i=1;i+len-1<=m;i++)
   {
      int l = i ; 
      int r = i+len-1 ; 
      if(lr[l-1]<rr[r+1]){ a=l;b=r; }
   }
   if(a!=0)
   {
      if(pos){res = send(a,b);} 
      return true ; 
   }
   return false ; 
}
int main()
{
   debugMode();
   char ch = 'a' ; 
   int idx = 1 ; 
   while(ch<='z')
   { 
      ci[ch] = idx ; 
      ic[idx] = ch ; 
      ch++ ; 
      idx++ ; 
   }
   string a,b ;
   cin >> a >> b ; 
   pa = a ; 
   pb = b ; 
   n = a.size() ; 
   m = b.size() ; 
   idx = 1  ;
   while(idx<=n)
   { 
      int x = ci[ a[idx-1] ] ; 
      ar[idx++] = x ; 
   }
   idx = 1  ;
   while(idx<=m)
   {
      lr[idx] = mod ; 
      rr[idx] = -mod ;
      int x = ci[ b[idx-1] ] ; 
      br[idx++] = x ; 
   }
   lr[0] = -mod ; 
   rr[m+1] = mod ; 
   idx = 1 ; 
   int last = 1 ; 
   while(idx<=m && last<=n)
   {
      int x = br[idx] ; 
      while(last<=n)
      {
        if(ar[last]==x){break;}
        last++ ; 
      }
      if(ar[last]!=x)
      {
         break ; 
      }
      else
      {
         lr[idx] = last ; 
         last++ ; 
      }
      idx++ ; 
   }

   
   idx = m ; 
   last = n ; 
   while(idx>0 && last>0)
   {
      int x = br[idx] ; 
      while(last>0)
      {
        if(ar[last]==x){break;}
        last-- ; 
      }
      if(ar[last]!=x)
      {
         break ; 
      }
      else
      {
         rr[idx] = last ; 
         last-- ; 
      }
      idx-- ; 
   }
   int l=0,r=m ; 
   while(l<=r)
   {
      int m = (l+r)/2 ; 
      if(valid(m,0))
      {
         r = m-1 ; 
         siz = m ; 
      }
      else
      {
         l = m+1 ; 
      }
   }
   bool hudai = valid(siz,1) ; 
   cout << res << endl ;
   return 0 ;
}