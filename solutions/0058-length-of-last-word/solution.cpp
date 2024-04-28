class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int tmp=0;
        for(auto x:s){
            if(x==' '){
                if(tmp!=0){
                    ans=tmp;
                }
                tmp=0;
            }
            else{
                tmp++;
            }
        }
        if(tmp!=0){
            ans=tmp;
        }
        return ans;
    }
};