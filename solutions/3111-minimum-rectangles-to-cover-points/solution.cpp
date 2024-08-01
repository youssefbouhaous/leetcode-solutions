class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int ans=0;
        int mxp=-1;
        sort(points.begin(),points.end());
        for(auto x:points){
            if(x[0]<=mxp){
                continue;
            }
            else{
                mxp=x[0]+w;
                ans++;
            }
        }
        return ans;
    }
};