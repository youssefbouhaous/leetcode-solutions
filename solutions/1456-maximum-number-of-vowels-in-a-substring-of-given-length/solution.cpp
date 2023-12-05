class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        vector<int>pre(n+1);
        for(int i=0;i<n;i++){
            bool f=0;
            for(char x:"aeiouAEIOU"){
                if(s[i]==x){
                    pre[i+1]=pre[i]+1;
                    f=1;
                    break;
                }
            }
            if(!f){
                pre[i+1]=pre[i];
            }
        }
        int ans=0;
        for(int i=0;i<=n-k;i++){
            ans=max(ans,pre[k+i]-pre[i]);
        }
        return ans;
    }
};