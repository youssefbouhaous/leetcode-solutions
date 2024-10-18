class Solution {
    int dp[1001][26][26];
    int f(int i,int start,int end,vector<string>& words){
        if(i==words.size())return 0;
        if(dp[i][start][end]!=-1)return dp[i][start][end];
        int m=words[i].size();
        int ans=1e9;
        if(words[i][m-1]-'a'==start){
            ans=m+f(i+1,words[i][0]-'a',end,words)-1;
        }
        else{
            ans=m+f(i+1,words[i][0]-'a',end,words);
        }
        if(words[i][0]-'a'==end){
            ans=min(m+f(i+1,start,words[i].back()-'a',words)-1,ans);
        }
        else{
            ans=min(m+f(i+1,start,words[i].back()-'a',words),ans);
        }
        return dp[i][start][end]=ans;
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        for(int i=0;i<1001;i++){
            for(int j=0;j<26;j++){
                for(int u=0;u<26;u++)dp[i][j][u]=-1;
            }
        }
        int n=words.size();
        return words[0].size() + f(1, words[0][0] - 'a', words[0].back() - 'a', words);
    }
};