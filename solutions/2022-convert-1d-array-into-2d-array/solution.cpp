class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>>ans;
        if(m*n!=o.size()) return ans;
        vector<int>p;
        for(int i=0;i<o.size();i++){
            p.push_back(o[i]);
            if(p.size()==n){
                ans.push_back(p);
                p.clear();
            }
        }
        return ans;
    }
};