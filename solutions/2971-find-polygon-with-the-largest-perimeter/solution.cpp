class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>pre(n+1);
        pre[1]=nums[0];
        for(int i=2;i<=n;i++){
            pre[i]=pre[i-1]+(long long)nums[i-1];
        }
        bool f=0;
        long long ans=-1;
        for(int i=3;i<=n;i++){
            if(pre[i-1]>(long long)nums[i-1]){
                ans=pre[i];
            }
        }
        return ans;
    }
};