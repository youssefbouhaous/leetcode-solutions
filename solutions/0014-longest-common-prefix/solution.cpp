class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string,int>m;
        for(auto x:strs){
            string tmp;
            for(auto y:x){
                tmp.push_back(y);
                m[tmp]++;
            }
        }
        string ans="";
        int mm=0;
        for(auto x:m){
            if(x.second==strs.size() && x.first.size()>ans.size()){
                ans=x.first;
            }
        }
        return ans;
    }
};