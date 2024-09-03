class Solution {
public:
    int getLucky(string s, int k) {
        string o;
        int ans;
        for(auto x:s){
            o+=to_string((int)(x-'a'+1));
        }
        while(k--){
            ans=0;
            for(auto x:o){
                ans+=x-'0';
            }
            o=to_string(ans);
        }
        return ans;
    }
};