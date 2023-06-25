class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int nans=1;
        string ans=s.substr(0,1);
        for(int i=0;i<n;i++){
            int l,r;
            l=i,r=i;
            while(l>-1 && r<n && s[l]==s[r]){
                if(r-l+1>nans){
                    nans=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--,r++;
            }
            l=i,r=i+1;
            while(l>-1 && r<n && s[l]==s[r]){
                if(r-l+1>nans){
                    nans=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--,r++;
            }
        }
        return ans;
    }
};