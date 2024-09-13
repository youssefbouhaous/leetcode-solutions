class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int>ans;
        int m=q.size();
        for(int i=0;i<m;i++){
            int t=arr[q[i][0]];
            for(int j=q[i][0]+1;j<=q[i][1];j++){
                t^=arr[j];
            }
            ans.push_back(t);
        }
        return ans;
    }
};