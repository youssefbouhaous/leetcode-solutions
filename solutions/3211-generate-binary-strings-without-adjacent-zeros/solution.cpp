class Solution {
public:
    set<string>ans;
    int nn;
    map<string,bool>v;
    void f(int i,string tmp){
        if(v[tmp]){
            return;
        }
        v[tmp]=true;
        if(i>nn){
            return;
        }
        for(int j=1;j<nn;j++){
            if(tmp[j]=='0' && tmp[j]==tmp[j-1]){
                return;
            }
        }
        ans.insert(tmp);
        for(int j=i;j<nn;j++){
            tmp[j]='0';
            f(j+1,tmp);
            tmp[j]='1';
            f(j+1,tmp);
        }
    }
    
    vector<string> validStrings(int n) {
        nn=n;
        string a(n,'1');
        f(0,a);
        vector<string>aa;
        for(auto x:ans){
            aa.push_back(x);
        }
        return aa;
        
    }
};