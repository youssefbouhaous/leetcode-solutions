class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double>ans;
        int l=0;
        int r=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(l<=r){
            double t=((double)nums[l]+(double)nums[r])/2;
            l++,r--;
            ans.push_back(t);
        }
        return *min_element(ans.begin(),ans.end());
    }
};