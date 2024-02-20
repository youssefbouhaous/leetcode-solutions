class Solution {
public:
    map<char,char>p;
    char find(char s){
        if(p[s]==s){
            return s;
        }
        return p[s]=find(p[s]);
    }
    void fu(char a,char b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(a>b){
                swap(a,b);
            }
            p[b]=a;
        }
    }
    string smallestEquivalentString(string s1, string s2, string b) {
        for(char i='a';i<='z';i++){
            p[i]=i;
        }
        for(int i=0;i<s1.size();i++){
            fu(s1[i],s2[i]);
        }
        string s="";
        for(auto x:b){
            s.push_back(find(x));
        }
        return s;
    }
};