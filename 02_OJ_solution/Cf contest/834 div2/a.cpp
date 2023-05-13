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
bool valid(char c)
{
   if(c=='Y' || c=='e' || c=='s'){return true;}
   return false ; 
}
void solve()
{
    map < char ,char > pq ; 
    pq['Y']='e' ;
    pq['e']='s' ;
    pq['s']='Y' ;
    string s ;
    cin >> s ; 
    int f = 1 ; 
    for (int i = 0; i+1 < s.size() ; ++i)
    {
        char a = s[i] ; 
        char b = s[i+1] ; 
        if(!valid(a) || !valid(b) ){f=0;}
        if(pq[a]!=b)
        {
           f = 0 ; 
        }
    } 
    int last = s.size()-1 ; 
    if(!valid(s[last])){f=0;}
    if(f)
    {
      cout << "YES" << endl ; 
    }
    else
    {
      cout << "NO" << endl ; 
    }
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