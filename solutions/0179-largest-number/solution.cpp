struct comp { 
    bool operator()(string& a, string& b) const
    { 
        return a+b<b+a;
    } 
}; 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>strs;
        for(auto x:nums){
            strs.push_back(to_string(x));
        }
        sort(strs.rbegin(),strs.rend(),comp());
        string ans;
        for(auto x:strs){
            ans+=x;
        }
        while(ans.size()>1 && ans[0]=='0'){
            ans=ans.substr(1,ans.size());
        }
        return ans;
    }
};