class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=to_string(nums[i])[0]-'0';
                int b=to_string(nums[j]).back()-'0';
                
                    if(gcd(a,b)==1){
                        ans++;
                    }
                
        }
        
        }
        return ans;
    }
};