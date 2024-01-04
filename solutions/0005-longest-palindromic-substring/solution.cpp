class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int c=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i-1;
            int r=i+1;
            int a=i;
            int b=i;
            while(l>=0 && r<n && s[l]==s[r]){
                a=l;b=r;
                l--;r++;
            }
            if(b-a+1>c){
                c=b-a+1;
                ans=s.substr(a,c);
            }
            r=i+1;
            l=i;
            a=i;
            b=i;
            while(l>= 0&& r<n && s[l]==s[r]){
                a=l;
                b=r;
                r++;
                l--;
            }
            if(b-a+1>c){
                c=b-a+1;
                ans=s.substr(a,c);
            }
        }
        return ans;
    }
};