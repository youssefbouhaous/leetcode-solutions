class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>pre;
        for(int i=0;i<n;i++){
            long long tmp=0;
            for(int j=i;j<n;j++){
                tmp=tmp+nums[j];
                pre.push_back(tmp);
            }
        }
        sort(pre.begin(),pre.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+pre[i])%1'000'000'007;
        }
        return ans;
    }
};