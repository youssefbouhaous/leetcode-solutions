#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define ll  int
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        ll g=0;
        ll l=0;
        int n=nums.size();
        indexed_set s;
        s.insert(nums[0]);
        for(int i=0;i<n;i++){
            if(abs(nums[i]-i)>1)return false;
        }
        return true;
    }
};