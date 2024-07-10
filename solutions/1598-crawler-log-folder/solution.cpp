class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto x:logs){
            if(x[0]=='.' && x[1]=='.' && ans>0){
                ans--;
            }
            else{
                if(x[0]!='.'){
                    ans++;
                }
            }
        }   
        return max(0,ans);
    }
};