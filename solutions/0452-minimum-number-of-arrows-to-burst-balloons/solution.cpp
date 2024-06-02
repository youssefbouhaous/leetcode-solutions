class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>>ans;
        sort(points.begin(),points.end());
        ans.push_back(points[0]);
        for(int i=0;i<points.size();i++){
            if(ans.back()[1]>=points[i][0]){
                ans.back()[1]=min(ans.back()[1],points[i][1]);
                ans.back()[0]=max(ans.back()[0],points[i][0]);
            }
            else{
                ans.push_back(points[i]);
            }
        }
        return ans.size();
    }
};