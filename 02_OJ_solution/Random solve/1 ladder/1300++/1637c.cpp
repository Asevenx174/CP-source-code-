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
     for (int i = 0; i < n ; ++i)
     {
        cin >> ar[i+1] ; 
     }
     int one=0,zero=0,idx ; 
     std:: set < int > o,e ;
     for(int i=2;i<n;i++)
     {
        if(ar[i]==1){one++;}
        else if(ar[i]==0){zero++;}
        if(ar[i]==0){continue;}
        if(ar[i]%2==1 && ar[i]>1){idx=i;}
        if(ar[i]%2==0)
        {
            e.insert(i) ; 
        }
        else
        {
            o.insert(i) ; 
        }
     }
     if(one==n-2 || (n==3 && ar[2]%2==1)) { cout << "-1" << endl ; continue ; }
     if(zero==n-2){cout << "0" << endl ; continue ; }
     int ans = 0 ; 
     
     if(e.empty())
     {
        ans++ ; 
        
        int x = idx ; 
        int val = ar[x] ; 
        auto it = o.upper_bound(x) ; 
        if(it!=o.end())
        {
           int y = *it ; 
           ar[y]-- ; 
           o.erase(y) ; 
           if(ar[y]>0)
           {
             e.insert(y) ; 
           }
        }
        if(it!=o.begin())
        {
           it-- ; 
           int y = *it ; 
           ar[y]-- ; 
           o.erase(y) ; 
           if(ar[y]>0)
           {
             e.insert(y) ; 
           }
        }
        val-=2 ; 
        ar[x] = val ;  
     }
     while(!e.empty())
     { 
        ans++ ; 
        auto lt = e.begin() ; 
        int x = *lt ; 
        int val = ar[x] ; 
        auto it = o.upper_bound(x) ; 
        if(it!=o.end())
        {
           int y = *it ; 
           ar[y]-- ; 
           o.erase(y) ; 
           if(ar[y]>0)
           {
             e.insert(y) ; 
           }
        }
        if(it!=o.begin())
        {
           it-- ; 
           int y = *it ; 
           ar[y]-- ; 
           o.erase(y) ; 
           if(ar[y]>0)
           {
             e.insert(y) ; 
           }
        }
        val-=2 ; 
        ar[x] = val ; 
        if(val==0)
        {
            e.erase(x) ;
        }
     }
     cout << ans << endl ;
   }
   return 0 ;
}