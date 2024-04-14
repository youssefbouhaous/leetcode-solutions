class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n=101;
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i] && i * i <= n) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        int mn=-1;
        int mx=-1;
        for(int i=0;i<nums.size();i++){
            if(is_prime[nums[i]]){
                mx=i;
                if(mn==-1){
                    mn=i;
                }
            }
        }
        return mx-mn;
    }
};