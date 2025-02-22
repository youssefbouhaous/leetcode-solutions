class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans(s.size(),'0');
        int cnt=0;
        for(auto x:s)cnt+=(x=='1');
        ans[0]='1';
        reverse(ans.begin(),ans.end());
        int i=0;
        cnt--;
        while(cnt--){
            ans[i++]='1';
        }
        return ans;
    }
};