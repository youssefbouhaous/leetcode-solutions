class Solution {
    void belman(vector<vector<string>>&p,vector<double>&r,unordered_map<string,double>&best){
        for(int i=0;i<p.size();i++){
            for(int j=0;j<p.size();j++){
                best[p[j][0]]=max(best[p[j][0]],best[p[j][1]]*1/r[j]);
                best[p[j][1]]=max(best[p[j][1]],best[p[j][0]]*r[j]);
            }
        }
    }
public:
    double maxAmount(string ic, vector<vector<string>>& p1, vector<double>& r1, vector<vector<string>>& p2, vector<double>& r2) {
        unordered_map<string,double>best;
        best[ic]=1;
        belman(p1,r1,best);
        belman(p2,r2,best);
        return best[ic];
    }
};