class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string tmp;
        for(auto x:s){
            if(x!=' '){
                tmp.push_back(x);
            }
            else{
                if(!tmp.empty()){
                    v.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        if(!tmp.empty()){
            v.push_back(tmp);
        }
        string ans;
        reverse(v.begin(),v.end());
        for(auto x:v){
            ans+=x+" ";
        }
        ans.pop_back();
        return ans;
    }
};