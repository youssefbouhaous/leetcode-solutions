#define double long double
const  double EPS = 1e-9;

class Solution {
public:
    pair<double,double> f(double x1,double y1,double x2,double y2){
        if(x1==x2){
            return {0.0,y1};
        }
        double a=(y1-y2)/(x1-x2);
        double b=y1-a*x1;
        return {a,b};
    }
    int minimumLines(vector<vector<int>>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        if(n<=2)return n-1;
        int ans=1;
        pair<double,double>p=f(s[0][0],s[0][1],s[1][0],s[1][1]);
        for(int i=2;i<n;i++){
            pair<double,double>b=f(s[i-1][0],s[i-1][1],s[i][0],s[i][1]);
            if(abs(b.first-p.first) > EPS || abs(b.second-p.second)> EPS ){
                ans++;
            }
            p=b;
        }
        return ans;
    }
};