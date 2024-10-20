class Solution {
public:
    vector<string> stringSequence(string t) {
        vector<string>ans={"a"};
        string o="a";
        while(o!=t){
            if(o.back()!=t[(int)o.size()-1]){
                o[(int)o.size()-1]++;
            }
            else if(o.size()<t.size()){
                o.push_back('a');
            }
            ans.push_back(o);
        }
        return ans;
    }
};