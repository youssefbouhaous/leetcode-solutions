class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,bool>v;
        for(auto x:nums1){
            for(int i=0;i<nums2.size();i++){
                if(!v[i] && nums2[i]==x){
                    v[i]=true;
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};