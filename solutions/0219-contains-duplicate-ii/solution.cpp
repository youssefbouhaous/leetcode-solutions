class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,set<int>>d;
        d[nums[0]].insert(0);
        for(int i=1;i<nums.size();i++){
            auto it=d[nums[i]].lower_bound(i-k);
            if(it!=d[nums[i]].end()){
                return true;
            }
            d[nums[i]].insert(i);
        }
        return false;
    }
};