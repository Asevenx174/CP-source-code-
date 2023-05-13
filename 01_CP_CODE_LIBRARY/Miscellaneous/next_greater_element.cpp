#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n;
    cin >> n ;
    int arr[n+5];
    for(int i=0;i<n;i++){int x ; cin >> x ; arr[i]=x ;}
    stack < int > s ;
    unordered_map < int,int > mp ;
    for(int i=0;i<n;i++)
    {
        int next = arr[i] ;
        if(s.empty()==true){s.push(next);continue;}
        while(s.empty()==false && s.top()<next)
        {
          mp[s.top()]=next;
          s.pop();
        }
        s.push(next);
    }
    while(s.empty()==false){mp[s.top()]=-1;s.pop();}
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " << mp[arr[i]] << endl;
    }
    return 0 ;
}
