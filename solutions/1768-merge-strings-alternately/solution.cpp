class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n=word1.size();
        int m=word2.size();
        for(int i=0;i<max(n,m);i++){
            if(i<n){
                ans.push_back(word1[i]);
            }
            if(i<m){
                ans.push_back(word2[i]);
            }
        }
        return ans;
    }
};