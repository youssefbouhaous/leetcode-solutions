class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string tmp;
            for(auto x:s){
                if(x=='z'){
                    tmp.push_back('a');
                }
                else{
                    tmp.push_back(x+1);
                }
            }
            s+=tmp;
        }
        return s[k-1];
    }
};