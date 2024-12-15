class Solution {
    void bellman(unordered_map<string,double>& best,vector<vector<string>>&p,vector<double>&r){
        for(int ri=0;ri<p.size();++ri){
            for(int i=0;i<p.size();++i){
                best[p[i][1]]=max(best[p[i][1]],best[p[i][0]]*r[i]);
                best[p[i][0]]=max(best[p[i][0]],best[p[i][1]]/r[i]);
            }
        }
    }
public:
    double maxAmount(string ic, vector<vector<string>>& p1, vector<double>& r1, vector<vector<string>>& p2, vector<double>& r2) {
        unordered_map<string,double>best;
        best[ic]=1;
        bellman(best,p1,r1);
        bellman(best,p2,r2);
        return best[ic];
    }
};