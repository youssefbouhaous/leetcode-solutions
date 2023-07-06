class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        if(n==1){
            return 0;
        }
        vector<int>pre(n+1);
        vector<int>suf(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]=nums[i]+pre[i];
            suf[n-i-1]=suf[n-i]+nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            if(pre[i]==suf[i+1]){
                return i;
            }
        }
        return -1;
    }
};