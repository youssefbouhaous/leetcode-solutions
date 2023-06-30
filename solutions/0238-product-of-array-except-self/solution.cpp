class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>-1;i--){
            suf[i]=suf[i+1]*nums[i];
        }
        vector<int>ans;
        ans.push_back(suf[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(suf[i+1]*pre[i-1]);
        }
        ans.push_back(pre[n-2]);
        return ans;
    }
};