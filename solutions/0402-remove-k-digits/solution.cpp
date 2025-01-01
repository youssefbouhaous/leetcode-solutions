class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k) return "0";
        string ans;
        int o=0;
        for(auto x:num){
            if(ans.empty()) ans.push_back(x);
            else{
                while(!ans.empty() && o<k && ans.back()>x){
                    ans.pop_back();
                    o++;
                }
                ans.push_back(x);
            }
        }
        while(o<k){
            ans.pop_back();
            o++;
        }
        if(ans.empty()){return "0";}
        reverse(ans.begin(),ans.end());
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
                reverse(ans.begin(),ans.end());
        if(ans.empty()){return "0";}

        return ans;
    }
};