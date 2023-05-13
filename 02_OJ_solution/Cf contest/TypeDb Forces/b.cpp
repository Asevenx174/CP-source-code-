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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
map < int ,int > pq ; 
set < int > s ; 
void primefactor(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        pq[2]++ ;
        s.insert(2) ;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            //cout << i << " ";
         pq[i]++ ;
        s.insert(i) ;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
      {
         pq[n]++ ;
        s.insert(n) ;
      }
}
void solve()
{
   int n ;
   cin >> n ; 
   primefactor(n) ; 
   ll ans = 0 ; 
   while(!s.empty())
   {
      ll temp = 1 ; 
      std::vector < int > v ;
      for(auto x : s)
      {
         //cout << " " << x ; 
         pq[x]-- ; 
         temp = temp*(ll)x ; 
         if(pq[x]==0)
         {
            v.push_back(x) ; continue ; 
         }
      }
     // cout << endl ;
      //cout << temp <<  "??" <<  endl ;
      ans+=temp ;
      for(auto x : v)
      {
         s.erase(s.find(x)) ; 
      }
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}