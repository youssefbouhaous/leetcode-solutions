class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>a;
        unordered_map<string,int>b;
        string tmp;
        for(auto x:s1){
            if(x==' ' && !tmp.empty()){
                a[tmp]++;
                tmp.clear();
            }
            else if(x!=' '){
                tmp.push_back(x);
            }
        }
        if(!tmp.empty()){
            a[tmp]++;
        }
        tmp.clear();
        for(auto x:s2){
            if(x==' ' && !tmp.empty()){
                b[tmp]++;
                tmp.clear();
            }
            else if(x!=' '){
                tmp.push_back(x);
            }
        }
        if(!tmp.empty()){
            b[tmp]++;
        }
        vector<string>ans;
        for(auto x:a){
            if(x.second==1 && b[x.first] ==0){
                ans.push_back(x.first);
            }
        }
        for(auto x:b){
            if(x.second==1 && a[x.first]==0) ans.push_back(x.first);
        }
        return ans;
    }
};