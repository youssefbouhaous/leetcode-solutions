class Solution {
public:
    bool areSentencesSimilar(string s, string t) {
        vector<string>tokena;
        vector<string>tokenb;
        string a;
        for(auto x:s){
            if(x==' '){
                if(!a.empty()){
                    tokena.push_back(a);
                }
                a.clear();
            }
            else{
                a.push_back(x);
            }
        }
        if(!a.empty()) tokena.push_back(a);
        string b;
        for(auto x:t){
            if(x==' '){
                if(!b.empty()){
                    tokenb.push_back(b);
                }
                b.clear();
            }
            else{
                b.push_back(x);
            }
        }
        if(!b.empty())tokenb.push_back(b);
        vector<bool>bl;
        int cnt=0;
        for(int i=0;i<min(tokena.size(),tokenb.size());i++){
            if(tokena[i]!=tokenb[i]){
                break;
            }
            cnt++;
        }
        int cnt2=0;
        for(int i=0;i<min(tokena.size(),tokenb.size());i++){
            if(tokena[(int)tokena.size()-i-1]!=tokenb[(int)tokenb.size()-i-1]){
                break;
            }
            cnt2++;
        }
        return (cnt+cnt2)>=(min(tokena.size(),tokenb.size()));
    }
};