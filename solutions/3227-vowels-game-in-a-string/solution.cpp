class Solution {
public:
    bool doesAliceWin(string s) {
        int c=0;
        for(auto x:s){
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                c++;
            }
        }
        if(c==0){
            return false;
        }
        return true;
    }
};