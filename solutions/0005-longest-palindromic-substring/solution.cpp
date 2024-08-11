class Solution {
public:
    string longestPalindrome(string s) {
        int len=1;
        string ans=s.substr(0,1);
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i-1;
            int lastl=i-1;
            int r=i+1;
            int tans=0;
            while(l>-1 && r<n){
                if(s[l]!=s[r]){
                    break;
                }
                else{
                    tans=r-l+1;
                    lastl=l;
                    l--,r++;
                }
            }
            if(tans>len){
                ans=s.substr(lastl,tans);
                len=tans;
            }
            l=i;
            lastl=i;
            r=i+1;
            tans=0;
            while(l>-1 && r<n){
                if(s[l]!=s[r]){
                    break;
                }
                else{
                    tans=r-l+1;
                    lastl=l;
                    l--,r++;
                }
            }
            if(tans>len){
                ans=s.substr(lastl,tans);
                len=tans;
            }
        }
        return ans;
    }
};