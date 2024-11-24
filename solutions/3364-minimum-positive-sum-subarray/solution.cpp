class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=i;j<min(i+r+1,n);j++){
                tmp+=nums[j];
                if(j-i+1>=l && j-i+1<=r){
                    if(ans==-1 && tmp>0){ans=tmp;}
                    else if(tmp>0){ans=min(ans,tmp);}
                }
            }
        }
        return ans;
    }
};