// C++ program to demonstrate the
// ordered set in GNU C++
#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int arr[200010];
int main()
{
	ordered_set o_set; /// here macro name is ordered_Set !

    int n,k;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        int x ;
        cin >> x ;
        arr[i]=x;
    }
    for(int i=1;i<=k;i++)
    {
        o_set.insert(arr[i]);
    }
    int pos = ((k+1)>>1)-1 ;

    int med = *(o_set.find_by_order(pos));

    int d = 0 ;
    for(int i=1;i<=k;i++)
    {
        d+=abs(med-arr[i]);
    }
    cout << d ;
    for(int i=k+1;i<=n;i++)
    {
        o_set.erase();
    }
	return 0 ;
}
