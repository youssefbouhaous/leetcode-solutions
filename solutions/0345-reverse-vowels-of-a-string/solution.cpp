class Solution {
public:
    string reverseVowels(string s) {
        string tmp;
        string v="aeiouAEIOU";
        for(auto x:s){
            if(count(v.begin(),v.end(),x)>0){
                tmp.push_back(x);
            }
        }
        for(int i=0;i<s.size();i++){
            if(count(v.begin(),v.end(),s[i])>0){
                s[i]=tmp.back();
                tmp.pop_back();
            }
        }
        return s;
    }
};