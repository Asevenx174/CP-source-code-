#include<bits/stdc++.h>
using namespace std ;
bool com( tuple < int,int,int > &a,tuple < int,int,int > &b )
{
    return get<1>(a)>get<1>(b);
}
int main()
{
    vector < tuple < int,int,int > > bad ;
    int n ;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin >> a >> b >> c ;
        bad.push_back(make_tuple(a,b,c));
    }
    sort(bad.begin(),bad.end());///based on 1st element
    cout << "based on 1st element" << endl;
    for(int i=0;i<n;i++)
    {
        int a = get<0>(bad[i]);
        int b = get<1>(bad[i]);
        int c = get<2>(bad[i]);
        cout << a << " " << b << " " << c << endl;
    }
    sort(bad.begin(),bad.end(),com);/// 2nd element
    cout << "Based on 2nd element" << endl;
    for(int i=0;i<n;i++)
    {
        int a = get<0>(bad[i]);
        int b = get<1>(bad[i]);
        int c = get<2>(bad[i]);
        cout << a << " " << b << " " << c << endl;
    }
    return 0 ;
}
