class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string r=to_string(nums[i]);
            for(int j=0;j<r.size();j++){
                r[j]=mapping[r[j]-'0']+'0';
            }
            v.push_back({stoi(r),i,nums[i]});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto x:v){
            ans.push_back(x[2]);
        }
        return ans;
    }
};