class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans=-1;
        for(int i=0;i<n-1;i++){
            int d=nums[i+1]-nums[i];
            int c=-1;
            int u=i;
            u++;
            if(d==1){
                c=2;
                while(u<n-1 && d*(nums[u+1]-nums[u])==-1){
                    d=nums[u+1]-nums[u];
                    c++;
                    u++;
                }
            }
            ans=max(ans,c);
        }
        return ans;
    }
};
