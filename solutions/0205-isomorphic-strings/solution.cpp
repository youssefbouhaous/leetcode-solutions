class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>d;
        map<char,char>d2;
        int n=s.size();
        for(int i=0;i<n;i++){
            d[s[i]]=t[i];
            d2[t[i]]=s[i];
        }
        for(int i=0;i<n;i++){
            if(d[s[i]]!=t[i] || d2[t[i]]!=s[i]){
                return false;
            }
            
        }
        return true;
    }
};