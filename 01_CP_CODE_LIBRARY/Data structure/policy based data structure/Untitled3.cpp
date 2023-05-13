#include<bits/stdc++.h>
using namespace std ;
int main()
{
    multiset < int > s ;
    int  n,q ;
    cin >> n >> q ;
    for(int i=0;i<n;i++)
    {
        int x ;
        cin >> x ;
        s.insert(x);
    }
    while(q--)
    {
        int x ;
        cin >> x ;
        if(x<0)
        {
            x = 0 - x ;
            s.erase(s.begin());
        }
        else
        {

        }
    }
    return 0 ;
}
