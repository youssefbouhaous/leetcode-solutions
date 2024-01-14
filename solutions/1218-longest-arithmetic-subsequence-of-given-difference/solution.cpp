class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        set<int>st;
        map<int,int>dp;
        dp[arr[0]]=1;
        st.insert(arr[0]);
        int ans=1;
        int n=arr.size();
        for(int i=1;i<n;i++){
            auto it=st.find(arr[i]-d);
            if(it!=st.end()){
                dp[arr[i]]=max(dp[*it]+1,dp[arr[i]]);
            }
            else{
                dp[arr[i]]=1;
            }
            st.insert(arr[i]);
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};