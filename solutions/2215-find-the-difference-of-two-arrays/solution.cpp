class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>a;
        set<int>b;
        for(auto x:nums1){
            a.insert(x);
        }
        for(auto x:nums2){
            b.insert(x);
        }
        vector<int>aa;
        vector<int>bb;
        for(auto x:a){
            if(b.count(x)==0){
                bb.push_back(x);
            }
        }
        for(auto x:b){
            if(a.count(x)==0){
                aa.push_back(x);
            }
        }
        vector<vector<int>>ans;
        ans.push_back(bb);
        ans.push_back(aa);
        return ans;
    }
};