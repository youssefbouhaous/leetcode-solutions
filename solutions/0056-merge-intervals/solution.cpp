class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        #define x intervals
        sort(x.begin(),x.end());
        vector<vector<int>>ans;
        ans.push_back(x[0]);
        for(int i=1;i<n;i++){
            if((x[i][0]>=ans.back()[0] && x[i][0]<=ans.back()[1]) ||x[i][0]<=ans.back()[0] && x[i][1]>=ans.back()[1]){
                ans.back()[0]=min(ans.back()[0],x[i][0]);
                ans.back()[1]=max(ans.back()[1],x[i][1]);
            }
            else{
                ans.push_back(x[i]);
            }
        }
        return ans;
    }
};