class Solution {
public:
    int maxOperations(string s) {
        int c=0;
        int ans=0;
        int n=s.size();
        if(s.back()=='0'){
            c=1;
        }
        for(int i=n-1;i>-1;i--){
            if(s[i]=='1'){
                ans+=c;
            }
            else if(i+1<n && s[i+1]=='1'){
                c++;
            }
        }
        return ans;
    }
};