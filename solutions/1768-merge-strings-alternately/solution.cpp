class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int n=word1.size();
        int m=word2.size();
        string ans;
        while(i<n || i<m){
            if(i<n){
                ans.push_back(word1[i]);
            }
            if(i<m){
                ans.push_back(word2[i]);
            }
            i++;
        }
        return ans;
    }
};