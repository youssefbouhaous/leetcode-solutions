class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>cnt(n+1,vector<int>(26));
        vector<int>cnt1(26);
        for(auto x:s1){
            cnt1[x-'a']++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                if(j==s2[i]-'a'){
                    cnt[i+1][j]=cnt[i][j]+1;
                }
                else{
                    cnt[i+1][j]=cnt[i][j];
                }
            }
        }
        for(int i=0;i<=n-m;i++){
            bool flag=true;
            for(int j=0;j<26;j++){
                if(cnt[i+m][j]-cnt[i][j]!=cnt1[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};