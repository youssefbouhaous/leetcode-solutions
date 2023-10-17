class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int u=j+1;u<n;u++){
                    double a=sqrt((points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                    double b=sqrt((points[i][0]-points[u][0])*(points[i][0]-points[u][0])+(points[i][1]-points[u][1])*(points[i][1]-points[u][1]));
                    double c=sqrt((points[u][0]-points[j][0])*(points[u][0]-points[j][0])+(points[u][1]-points[j][1])*(points[u][1]-points[j][1]));
                    double s=(a+b+c)/2;
                    double aa=sqrt(s*(s-a)*(s-b)*(s-c));
                    ans=max(ans,aa);
                }
            }
        }
        return ans;
    }
};