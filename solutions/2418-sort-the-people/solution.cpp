class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>v;
        for(int i=0;i<names.size();i++){
            v.push_back({heights[i],names[i]});
        }
        sort(v.rbegin(),v.rend());
        vector<string>ans;
        for(auto x:v){
            ans.push_back(x.second);
        }
        return ans;
    }
};