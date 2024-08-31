/*
n obstacles
foreach i construct arr such that
choose from 0 to i-1 and choose i such that arr is no decreasing
what is the recursion ?
1,2,3,2

1
2->1
3->2->1
2->3*
2->2->1
*/

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ln '\n'
typedef long long ll;



class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        vector<int>ans;
        ordered_set<int>st;
        st.insert(o[0]);
        ans.push_back(1);
        for(int i=1;i<o.size();i++){
            ans.push_back(st.order_of_key(o[i]+1)+1);
            if(o[i]>=(*(--st.end()))){
                st.insert(o[i]);
            }
            else{
                auto it=st.lower_bound(o[i]);
                if(it!=st.end()){
                st.erase(it);
                st.insert(o[i]);
                }
            }
        }
        return ans;
    }
};