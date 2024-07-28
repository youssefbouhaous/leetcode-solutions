class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        long long a=0;
        long long b=0;
        for(auto x:nums){
            if(x>9){
                a+=x;
            }
            else
                b+=x;
        }
        return a!=b;
    }
};