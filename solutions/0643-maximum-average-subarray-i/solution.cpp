class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double>pre(nums.size(),0);
        pre[0]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        double m=((double)pre[k-1])/((double)k);
        for(int i=k;i<n;i++){
            m=max(m,((double)(pre[i]-pre[i-k]))/((double)k));
        }
        return m;
    }
};