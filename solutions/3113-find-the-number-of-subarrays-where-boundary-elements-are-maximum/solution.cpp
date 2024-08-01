class Solution {
    
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>st;
        long long ans=0;
        for(auto x:nums){
            if(st.empty() || x>st.back().first){
                while(!st.empty() && st.back().first<x){
                    st.pop_back();
                }
                if(st.empty() || st.back().first>x)
                st.push_back({x,1});
                else
                    st.back().second++;
                ans+=st.back().second;
            }
            else{
                if(st.back().first==x){
                    st.back().second++;
                    ans+=st.back().second;
                }
                else{
                    st.push_back({x,1});
                    ans++;
                }
            }
        }
        return ans;
    }
};