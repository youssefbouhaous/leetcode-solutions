class Solution {
public:
    map<string,string>p;
    string find(string s){
        if(p[s]==""){
            p[s]=s;
        }
        if(p[s]==s){
            return s;
        }
        return p[s]=find(p[s]);
    }
    void funion(string s,string r){
        s=find(s);
        r=find(r);
        if(s!=r){
            p[r]=s;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        for(int i=0;i<a.size();i++){
            for(int j=1;j<a[i].size();j++){
                funion(a[i][1],a[i][j]);
            }
        }
        map<string,vector<string>>grps;
        for(int i=0;i<a.size();i++){
            for(int j=1;j<a[i].size();j++){
                grps[find(a[i][1])].push_back(a[i][j]);
            }
        }
        vector<set<string>>ans;
        map<string,bool>vv;
        queue<string>q;
        for(int i=0;i<a.size();i++){
            if(!vv[a[i][1]]){
                set<string>tmp;
                q.push(a[i][0]);
                vv[a[i][1]]=true;
                for(auto x:grps[find(a[i][1])]){
                    vv[x]=true;
                    tmp.insert(x);
                }
                ans.push_back(tmp);
            }
        }
        vector<vector<string>>anns;
        for(auto x:ans){
            vector<string>tmp;
            tmp.push_back(q.front());
            q.pop();
            for(auto y:x){
                tmp.push_back(y);
            }
            anns.push_back(tmp);
        }
        return anns;
    }
};