class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int>pre(s.size()+1,0);
        string v="aeiouAEIOU";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(count(v.begin(),v.end(),s[i])>0){
                pre[i+1]=pre[i]+1;
            }
            else{
                pre[i+1]=pre[i];
            }
        }
        int m=pre[k];
        for(int i=k;i<=n;i++){
            m=max(m,pre[i]-pre[i-k]);
        }
        return m;
    }
};