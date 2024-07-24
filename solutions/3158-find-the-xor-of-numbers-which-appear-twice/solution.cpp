class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int>cnt;
        int ans=0;
        int f=0;
        for(auto x:nums){
            cnt[x]++;
            if(cnt[x]==2){
                f=x;
            }
        }
        ans=f;
        for(auto x:cnt){
            if(x.second==2 && x.first!=f){
                ans^=x.first;
            }
        }
        return ans;
    }
};