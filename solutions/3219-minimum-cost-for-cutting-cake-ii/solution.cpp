#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        long long ans=0;
        ordered_set<int>hs;
        vector<long long>suf(m,0);
        vector<long long>pre(m,0);
        for(auto x:h){
            ans+=(long long)x;
            hs.insert(x);
        }
        for(auto x:v){
            ans+=(long long)x;
        }
        sort(h.begin(),h.end());
        for(int i=m-2;i>=0;i--){
            suf[i]=suf[i+1]+(long long)h[i];
        }
        for(int i=1;i<m;i++){
            pre[i]=pre[i-1]+(long long)h[i-1];
        }
        for(int i=0;i<n-1;i++){
            int pos=hs.order_of_key(v[i]);
            ans+=(m-pos-1)*(long long)(v[i]);
            ans+=pre[pos];
        }
        return ans;
    }
};