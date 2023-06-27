class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=1;
        map<int,int>dp;
        dp[arr[n-1]]=1;
        set<int>st;
        st.insert(arr[n-1]);
        for(int i=n-2;i>-1;i--){
            auto it=st.find(arr[i]+d);
            //cout<<*it<<endl;
            if(it!=st.end()){
                dp[arr[i]]=max(dp[*it]+1,dp[arr[i]]);
            }
            else{
                dp[arr[i]]=max(dp[arr[i]],1);
            }
            //cout<<dp[arr[i]]<<" :: \n";
            st.insert(arr[i]);
            ans=max(dp[arr[i]],ans);
        }
        return ans;
    }
    
};