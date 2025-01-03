class Solution {
public:
    int minOperations(string s) {
        string a;
        string b;
        int o=0;
        int o1=1;
        a.push_back(s[0]);
        b.push_back((s[0]=='0')?'1':'0');
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]!=a.back()){
                a.push_back(s[i]);
            }
            else{
                o++;
                a.push_back((s[i]=='0')?'1':'0');
            }
            if(s[i]!=b.back()){
                b.push_back(s[i]);
            }
            else{
                o1++;
                b.push_back((s[i]=='0')?'1':'0');
            }
            
        }
        return min(o,o1);
    }
};