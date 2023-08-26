class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            bitset<32> tmp(i);
            int s=0;
            for(auto x:tmp.to_string()){
                if(x=='1'){
                    s++;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};