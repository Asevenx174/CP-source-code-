// C++ program to demonstrate the
// ordered set in GNU C++
#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,  less_equal <data_type> , rb_tree_tag,tree_order_statistics_node_update>

int main()
{
   ordered_set o_set; /// here macro name is ordered_Set !

   /// ordered set store distinct shorted elements

    o_set.insert(7);
    o_set.insert(4);
    o_set.insert(10);
    o_set.insert(25);
    o_set.insert(16);

    cout <<  o_set.order_of_key(15) << endl ; /// 15 er choto 3 ta element ase !

    auto it = o_set.find_by_order(3);/// 4th element er iterator return kre
    cout << *it << endl;

    if(o_set.find(25)!=o_set.end())
    {
        o_set.erase(o_set.find(25));
    }
   return 0;
}
