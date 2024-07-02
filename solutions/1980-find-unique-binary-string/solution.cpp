class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        string s(m,'0');
        for(int i=0;i<m;i++){
            bool f=true;
            for(auto x:nums){
                if(x==s){
                    f=false;
                    break;
                }
            }
            if(f){
                return s;
            }
            s[i]='1';
        }
        return s;
    }
};