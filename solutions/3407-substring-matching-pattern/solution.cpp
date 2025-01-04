class Solution {
public:
    bool hasMatch(string s, string p) {
        string a;
        string b;
        int i=0;
        while(i<p.size()){
            if(p[i]=='*') break;
            a.push_back(p[i]);
            i++;
        }
        i++;
        while(i<p.size()){
            b.push_back(p[i]);
            i++;
        }
        size_t pos = s.find(a);
        if (pos == string::npos) return false;
        if(s.find(b,pos+a.size())==string::npos)return false;
        return true;
    }
};