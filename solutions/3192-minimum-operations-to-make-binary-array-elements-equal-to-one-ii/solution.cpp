class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool f=true;
        for(auto x:nums){
            if(x==0){
                f=false;
            }
        }
        if(f){
            return 0;
        }
        int var=false;
        int ans=0;
        for(auto x:nums){
            if(!var){
                if(x==0){
                    var=true;
                    ans++;
                }
            }
            else{
                if(x==1){
                    var=false;
                    ans++;
                }
            }
        }
        return ans;
    }
};