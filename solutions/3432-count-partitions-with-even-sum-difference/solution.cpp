class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int a=0;
        for(int i=0;i<n-1;i++){
            a+=nums[i]%2;
            int b=0;
            for(int j=i+1;j<n;j++){
                b+=nums[j]%2;
            }
            if(a%2==b%2)ans++;
        }
        return ans;
    }
};