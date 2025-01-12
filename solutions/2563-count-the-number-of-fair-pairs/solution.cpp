class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lo, int up) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long o=0;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            int la=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(nums[m]+nums[i]>=lo){
                    la=(la==-1)?m:min(la,m);
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            l=i+1;
            r=n-1;
            int lb=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(nums[m]+nums[i]<=up){
                    lb=(lb==-1)?m:max(lb,m);
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
            if(la!=-1 && lb!=-1){
                ans=ans+(lb-la+1);
            }
        }
        return ans;
    }
};