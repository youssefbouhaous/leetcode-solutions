class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto x:nums){
            if(x==2){ans.push_back(-1);continue;}
            bitset<32>b(x);
            for(int i=0;i<32;i++){
                if(b[i]==1 && b[i+1]==0){
                    b[i]=0;
                    break;
                }
            }
            ans.push_back((int)(b.to_ulong()));
            
        }
        return ans;
    }
};