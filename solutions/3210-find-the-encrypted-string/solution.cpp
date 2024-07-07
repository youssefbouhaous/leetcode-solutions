class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
        string ans(n,' ');
        for(int i=0;i<n;i++){
            ans[i]=s[(i+k)%n];
        }
        return ans;
    }
};