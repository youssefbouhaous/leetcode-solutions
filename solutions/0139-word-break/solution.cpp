class Solution {
public:
    bool ans=false;
    map<pair<string,int>,bool>d;
    void f(int i,string s,vector<string>& wordDict){
        if(i>=s.size()){
            ans=true;
            return;
        }
        for(auto x:wordDict){
            bool fg=true;
            if(i+x.size()>s.size()){
                continue;
            }
            for(int j=0;j<x.size();j++){
                if(s[j+i]!=x[j]){
                    fg=false;
                    break;
                }
            }
            if(fg && d[{x,i+x.size()}]!=true){
                d[{x,i+x.size()}]=true;
                f(i+x.size(),s,wordDict);
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        f(0,s,wordDict);
        return ans;
    }
};