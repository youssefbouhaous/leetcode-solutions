class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>groups;
        for(auto x:strs){
            string tmp=x;
            sort(tmp.begin(),tmp.end());
            groups[tmp].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto x:groups){
            ans.push_back(x.second);
        }
        return ans;
    }
};