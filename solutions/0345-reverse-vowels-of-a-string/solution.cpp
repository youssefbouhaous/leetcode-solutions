class Solution {
public:
    string reverseVowels(string s) {
        string v="aeiouAEIOU";
        string a="";
        for(int i=0;i<s.size();i++){
            for(auto x:v){
                if(s[i]==x){
                    a.push_back(s[i]);
                    break;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            for(auto x:v){
                if(s[i]==x){
                    char o=a.back();
                    a.pop_back();
                    s[i]=o;
                    break;
                }
            }
        }
        return s;
    }
};