class Solution {
public:
    int f(string&a,string&b){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                c++;
            }
        }
        return c;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,bool>d;
        map<string,vector<string>>g;
        for(auto x:wordList){
            for(int i=0;i<x.size();i++){
                string tmp=beginWord;
                tmp[i]='*';
                g[tmp].push_back(beginWord);
            }
        }
        for(auto x:wordList){
            for(int i=0;i<x.size();i++){
                string tmp=x;
                tmp[i]='*';
                g[tmp].push_back(x);
            }
        }
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        d[beginWord]=true;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p.second==endWord){
                return p.first+1;
            }
            for(int i=0;i<p.second.size();i++){
                string tmp=p.second;
                tmp[i]='*';
                for(auto x:g[tmp]){
                    if(!d[x]){
                        q.push({p.first+1,x});
                        d[x]=true;
                    }
                }
            }
        }
        return 0;
    }
};