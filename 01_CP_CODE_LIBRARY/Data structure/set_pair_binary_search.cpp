#include<bits/stdc++.h>
#define pii pair < int,int >
#define ff first
#define ss second
using namespace std ;
const int maxx = 2e5+10;
set < pii > q ;
int arr[maxx+5],a[maxx+5];
int main()
{
    int n,m,d;
    cin >> n >> m >> d ;
    for(int i=1;i<=n;i++)
    {
        int x ;
        cin >> x ;
        a[i]=x;
        q.insert({x,i});
    }
    int par=0;
    while(!q.empty())
    {
        par++;
        int sidx = q.begin()->ss;
        arr[sidx]=par;
        q.erase(q.begin());
        while(true)
        {
            auto next = q.lower_bound({a[sidx]+d+1,0});
            if(next==q.end()){break;}
            sidx=next->ss;
            q.erase(next);
            arr[sidx]=par;
        }
    }
    cout << par << endl;
    for(int i=1;i<=n;i++)
    {
        if(i!=1){cout << " " ;}
        cout << arr[i] ;
    }
    cout << endl;
    return 0 ;
}
