#include<bits/stdc++.h>
using namespace std ;
vector < int > v ;
int main()
{
    int test ;
    cin >> test ;
    while(test--)
    {
        v.clear();
        int n ;
        cin >> n ;
        for(int i=0;i<n;i++)
        {
            int x ;
            cin >> x ;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int temp=0;
        for(int i=0;i<v.size();i++)
        {
            int k=1;
            while(k<v[i] && i<v.size())
            {
                i++;
                k++;
            }
            if(k==v[i]){temp++;}
        }
        cout << temp << endl;
    }
    return 0 ;
}
