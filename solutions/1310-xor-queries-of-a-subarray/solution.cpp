class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int>ans;
        vector<int>pre;
        int n=arr.size();
        int t=arr[0];
        pre.push_back(0);
        pre.push_back(t);
        for(int i=1;i<n;i++){
            t^=arr[i];
            pre.push_back(t);
        }
        for(auto x:q){
            ans.push_back(pre[x[1]+1]^pre[x[0]]);
        }
        return ans;
    }
};