class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string t;
            for(int i=0;i<s.size()-1;i++){
                int o=((s[i]-'0')+(s[i+1]-'0'))%10;
                t.push_back(o+'0');
            }
            s=t;
        }
        return s[0]==s[1];
    }
};