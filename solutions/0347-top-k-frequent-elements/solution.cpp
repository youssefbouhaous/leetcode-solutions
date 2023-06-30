class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<int>st;
        map<int,int>d;
        map<int,vector<int>>dd;
        for(auto x:nums){
            d[x]++;
            st.insert(x);
        }
        for(auto x:d){
            st.insert(x.second);
            dd[x.second].push_back(x.first);
        }
        vector<int>stt;
        for(auto x:st){
            stt.push_back(x);
        }
        vector<int>ans;
        for(int i=stt.size()-1;i>=0 && ans.size()<k;i--){
            for(auto x:dd[stt[i]]){
                ans.push_back(x);
            }
        }
        return ans;
    }
};