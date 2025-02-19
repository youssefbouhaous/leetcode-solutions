class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>m;
        for(auto x:paths){
            m[x[0]]++;
        }
        for(auto x:paths){
            if(m[x[1]]==0)return x[1];
        }
        return "";
    }
};