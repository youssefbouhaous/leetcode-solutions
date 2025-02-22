class Solution {
public:
    int titleToNumber(string c) {
        int ans=0;
        reverse(c.begin(),c.end());
        int n=c.size();
        long long o=1;
        for(int i=0;i<n;i++){
            ans+=o*(c[i]-'A'+1);
            o*=26;
        }
        return ans;
    }
};