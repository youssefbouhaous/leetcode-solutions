class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double>pre(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        double ans=pre[k]/k;
        for(int i=0;i<=n-k;i++){
            ans=max(ans,(pre[k+i]-pre[i])/k);
        }
        return ans;
    }
};