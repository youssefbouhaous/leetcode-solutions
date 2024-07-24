class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(auto x:s){
            if(x>='0' && x<='9'){
                if(!ans.empty()) {
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(x);
            }
        }
        return ans;
    }
};