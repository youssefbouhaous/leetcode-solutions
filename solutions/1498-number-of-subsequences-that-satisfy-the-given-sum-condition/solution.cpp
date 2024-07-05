class Solution {
public:
    int numSubseq(vector<int>& nums, int t) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>pow(n,1);
        int mod=1000'000'007;
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        int ans=0;
        int l=0;
        int r=n-1;
        while(l<=r){
            if(nums[r]+nums[l]<=t){
                ans+=pow[r-l];
                ans=ans%mod;
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};