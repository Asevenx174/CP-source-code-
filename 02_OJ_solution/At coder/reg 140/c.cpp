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
int ar[maxx+10] ; 
int main()
{
   debugMode();
   int n,l,r ;
   cin >> n >> r >> l ; 
   std::vector < int > u,v,br ;
   br.push_back(0) ;
   lp(i,1,n)
   {
      cin >> ar[i] ; 
      if(ar[i]==l)
      {
         u.push_back(i) ; 
      }
      else if(ar[i]==r)
      { 
         v.push_back(i) ; 
      }
      else if(ar[i]<l || ar[i]>r)
      {
         br.push_back(i) ; 
      }
   }
   br.push_back(n+1) ; 
   int a=0,b=0 ; 
   ll ans = 0 ,res = 0 ; 
   for(auto x : br )
   {
      //cout << x << endl ;
      if(x==0){continue;}
      b = x ;
      //cout << a+1 << " " << b-1 << endl ;
      if(a+1<b && l==r)
      {
         ll prev = a ; 
         auto it = upper_bound(u.begin(),u.end(),a) ; 
         while(it!=u.end())
         {
            if(*it>=b){break;}
            res+=(b-prev-1) ; 
            prev = *it ; 
            it++ ;  
         }
      }
      if(a+1<b)
      {  
         int le = a+1 ;
         int re = b-1 ; 
         //cout << le << " " << re << " " <<  << endl ;
         auto it = upper_bound(u.begin(),u.end(),a) ; 
         auto lt = upper_bound(v.begin(),v.end(),a) ; 
         if(it==u.end() || lt==v.end()){a=x;continue;}
         int lastx = *it ; 
         int lasty = *lt ; 
         if(max(lastx,lasty)>=b){a = x ; continue;}
         ll p = min(lastx,lasty)-a ;
         ll q = b-max(lastx,lasty) ; 
         ans+=(p*q) ; 
         while(1)
         {
            if(lastx<lasty)
            {
               it = upper_bound(u.begin(),u.end(),lastx) ; 
               if(it==u.end()){break;}
               ll newx = *it ;
               if(newx<lasty)
               {
                  p = newx-lastx ; 
                  q = b-lasty ;  
               }
               else
               { 
                  if(newx>=b){break;}
                  p = lasty-lastx ; 
                  q = b-newx ;  
               }
               lastx = newx ; 
            }
            else
            { 
               lt = upper_bound(v.begin(),v.end(),lasty) ; 
               if(lt==v.end()){break;}
               ll newy = *lt ;
               if(newy<lastx)
               {
                  // lasty newy lastx 
                  p = newy-lasty ; 
                  q = b-lastx ;  
               }
               else
               { 
                  // lasty lastx newy 
                  if(newy>=b){break;}
                  p = lastx-lasty ; 
                  q = b-newy ;  
               }
               lasty = newy ; 
            }
            ans+=(p*q) ; 
         }
      }

      a = x ;   
   }
   if(l==r)
   {
      ans = res ; 
   }
   cout << ans << endl ;
   return 0 ;
}