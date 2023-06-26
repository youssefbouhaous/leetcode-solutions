class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        vector<int>dp(n,1);
        vector<set<int>>adp;
        set<int>a1;
        a1.insert(nums[0]);
        adp.push_back(a1);
        for(int i=1;i<n;i++){
            int c=1;
            bool f=0;
            for(int j=ans-1;j>-1;j--){
                auto it=adp[j].lower_bound(nums[i]);
                if(it!=adp[j].begin()){
                    set<int>b;
                    f=1;
                    if(j<ans-1){
                        adp[j+1].insert(nums[i]);
                    }
                    else{
                        set<int>b;
                        b.insert(nums[i]);
                        adp.push_back(b);
                    }
                    c=j+2;
                    break;
                }
            }
            if(f==0){
                adp[0].insert(nums[i]);
            }
            dp[i]=c;
            ans=max(ans,dp[i]);
        }/*
        for(auto x:adp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }*/
        return ans;
    }
};