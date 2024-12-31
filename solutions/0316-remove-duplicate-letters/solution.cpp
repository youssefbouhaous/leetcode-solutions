class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        int n=s.size();
        set<char>in;
        vector<vector<int>>suf(n+1,vector<int>(26));
        for(int i=n-1;i>-1;i--){
            for(int j=0;j<26;j++){
                if(j==s[i]-'a'){
                    suf[i][j]=suf[i+1][j]+1;
                }
                else{
                    suf[i][j]=suf[i+1][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(in.count(s[i])){
                continue;
            }
            bool add=true;int id=-1;
            for(int j=i+1;j<n;j++){
                if(s[j]<s[i] && in.count(s[j])==0){
                    id=j;break;
                }
            }
            if(id==-1){
                ans.push_back(s[i]);
                in.insert(s[i]);
            }
            else if(suf[id][s[i]-'a']==0){
                ans.push_back(s[i]);
                in.insert(s[i]);
            }
            else{
                for(int j=i+1;j<id;j++){
                    if(suf[id][s[j]-'a']==0 && in.count(s[j])==0){
                        add=false;
                        break;
                    }
                }
                if(!add){
                    ans.push_back(s[i]);
                in.insert(s[i]);
                }else{
                    i=id-1;
                }
            }
        }
        return ans;
    }
};