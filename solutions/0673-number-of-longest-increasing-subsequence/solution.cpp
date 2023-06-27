class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>dp(n,pair<int,int>{1,1});
        dp[n-1]={1,1};
        for(int i=n-2;i>-1;i--){
            int c=0;
            int l=1;
            for(int j=n-1;j>i;j--){
                if(nums[i]<nums[j]){
                    if(c<dp[j].first){
                        c=dp[j].first;
                        l=dp[j].second;
                    }
                    else if(c==dp[j].first){
                        l+=dp[j].second;
                    }
                }
            }
            dp[i].first=c+1;
            dp[i].second=l;
        }
        int s=0;
        int cs=0;
        int cc=0;
        /*
        for(auto x:dp){
            cout<<x.first<<" ";
        }
        cout<<endl;
        for(auto x:dp){
            cout<<x.second<<" ";
        }
        cout<<endl;
        */
        for(int i=0;i<n;i++){
            if(dp[i].first>cc){
                cc=dp[i].first;
                s=dp[i].second;
            }
            else if(dp[i].first==cc){
                s+=dp[i].second;
            }
        }
        return s;
    }
};