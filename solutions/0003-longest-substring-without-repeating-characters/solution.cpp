class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        map<char,int>c;
        while(r<s.size()){
            if(c[s[r]]!=0){
                l=max(c[s[r]],l);
            }
            ans=max(r-l+1,ans);
            cout<<" "<<s[r] <<" "<<ans<<" "<<" "<<r<<" "<<l<<endl;
            c[s[r]]=r+1;
            r++;
        }
        return ans;
    }
};