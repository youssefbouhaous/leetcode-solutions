class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c=0;
        int id=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[id]){
                c++;
                id++;
            }
            if(id==s.size()){
                return true;
            }
        }
        return c==s.size();
    }
};