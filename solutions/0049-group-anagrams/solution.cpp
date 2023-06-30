class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<string,vector<string>>d;
        for(auto x:strs){
            string tmp=x;
            sort(tmp.begin(),tmp.end());
            d[tmp].push_back(x);
        }
        vector<vector<string>>ans;
        int i=0;
        for(auto x:d){
            ans.push_back(x.second);
        }
        return ans;
    }
};