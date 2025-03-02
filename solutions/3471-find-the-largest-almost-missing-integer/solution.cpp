class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            set<int>st;
            for(int j=i;j<min(i+k,n);j++){
                st.insert(nums[j]);
            }
            for(auto x:st){mp[x]++;}
        }
        int mx=-1;
        for(auto x:mp){
            if(x.second==1)mx=max(mx,x.first);
        }
        return mx;
    }
};