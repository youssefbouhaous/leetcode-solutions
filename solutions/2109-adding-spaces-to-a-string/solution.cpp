class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int i=0;
        for(int j=0;j<(int)s.size();j++){
            //cout<<i<<endl;
            if(i<spaces.size() && j==spaces[i]){
                ans.push_back(' ');
                i++;
            }
            ans.push_back(s[j]);
        }
        return ans;
    }
};