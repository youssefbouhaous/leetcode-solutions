
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0;
        int r=0;
        vector<int>cnt(52);
        vector<vector<int>>dict(n+1,vector<int>(52));
        for(int i=0;i<m;i++){
            if(isupper(t[i]))
            cnt[t[i]-'A']++;
            else cnt[26+t[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<52;j++){
                if(isupper(s[i])){
                if(j==s[i]-'A'){
                    dict[i+1][j]=dict[i][j]+1;
                }
                else{
                    dict[i+1][j]=dict[i][j];
                }}
                else{
                 if(j==s[i]-'a'+26){
                    dict[i+1][j]=dict[i][j]+1;
                }
                else{
                    dict[i+1][j]=dict[i][j];
                }   
                }
            }
        }
        pair<int,int>ans={-1,-1};
        while(r<n){
            bool f=true;
            for(int j=0;j<52;j++){
                if(dict[r+1][j]-dict[l][j]<cnt[j]){
                    f=false;
                    break;
                }
            }
            if(f){
                if(ans.first==-1){
                    ans={l,r};
                }
                else if(ans.second-ans.first>r-l){
                    ans={l,r};
                }
                l++;
                if(l>r){
                    r=l;
                }
            }
            else{
                r++;
            }
        }
        if(ans.first==-1) return "";
        return s.substr(ans.first,ans.second-ans.first+1);
    }
};