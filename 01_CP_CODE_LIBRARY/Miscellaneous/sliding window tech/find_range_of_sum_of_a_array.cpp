#include<bits\stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std ;
map < int ,int > m ;
void range(int n,int sum,int arr[100])
{
    int curr=0;
    rep(i,n)
    {
        curr+=arr[i];
        if(curr==sum)
        {
            cout << "0" << " " << i << endl; return ;
        }
        if(m.find(curr-sum)!=m.end())
        {
            cout << m[curr-sum]+1 << " " << i << endl;return ;
        }
        m[curr]=i;
    }
    cout << "No range" << endl;
}
int main()
{
    int n,arr[100],sum;
    cin >> n >> sum ;
    rep(i,n)
    {
        cin >> arr[i] ;
    }
    range(n,sum,arr);
    return 0 ;
}
