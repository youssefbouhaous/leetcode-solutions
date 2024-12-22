class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        int ans=0;
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        if(st.size()==nums.size())return ans;
        while(true){
            ans++;
            if(nums.size()<3)return ans;
            nums.pop_back();
            nums.pop_back();
            nums.pop_back();
            set<int>st;
            for(auto x:nums){
                st.insert(x);
            }
            if(st.size()==nums.size())return ans;
        }
    }
};