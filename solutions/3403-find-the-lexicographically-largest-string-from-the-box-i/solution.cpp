class Solution {
public:
    string answerString(string word, int nm) {
        string ans;
        int n=word.size();
        if(nm==1)return word;
        int ln=n-nm+1;
        char mx=word[0];
        ans.push_back(mx);
        for(auto x:word)mx=max(x,mx);
        for(int i=0;i<n;i++){
            string tmp;
            if(mx==word[i]){
                tmp.push_back(mx);
                int j=i+1;
                while(tmp.size()<ln && j<n){
                    tmp.push_back(word[j]);
                    j++;
                }
                if(tmp>ans){
                    ans=tmp;
                }
            }
        }
        return ans;
    }
};