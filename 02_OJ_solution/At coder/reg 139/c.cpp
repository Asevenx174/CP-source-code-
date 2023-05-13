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
int best = 0 ,n,k ; 
string s[20] ; 
int sett(int idx,int mask )
{
   mask = mask | (1<< (idx-1)) ; 
   return mask ; 
}
bool check(int idx,int mask )
{
   if( (mask&(1<<(idx-1))) ==0 )
   {
      return false ; 
   }
   return true ; 
}
void calco(int idx,int mask)
{
     if(idx>n)
     {
       map < char ,int > ans ; 
       for(int i=1;i<=n;i++)
       {
          if(check(i,mask))
          {
             map < char , bool > pq ; 
             for(auto c : s[i] )
             {
                if(!pq[c]){ans[c]++;}
                pq[c] = true ; 
             }
          }
       }
       char c = 'a' ; 
       int sum = 0 ; 
       while(c<='z')
       {
         if(ans[c]==k){sum++;}
         c++ ; 
       }
       best = max(best,sum) ; 
       return  ; 
     }

     calco(idx+1,sett(idx,mask));
     calco(idx+1,mask);
}
int main()
{
   debugMode();
   cin >> n >> k ;
   for (int i = 1 ; i <= n ; ++i)
   {
      cin >> s[i] ; 
   }
   calco(0,0) ; 
   cout << best << endl ;
   return 0 ;
}