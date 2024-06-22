class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<int>pre(n+1);
        multiset<int>s;
        s.insert(0);
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                pre[i+1]=pre[i]+1;
            }
            else{
                pre[i+1]=pre[i];
            }
            if(s.count(pre[i+1]-k)){
                ans+=s.count(pre[i+1]-k);
            }
            s.insert(pre[i+1]);
        }
        return ans;
    }
};