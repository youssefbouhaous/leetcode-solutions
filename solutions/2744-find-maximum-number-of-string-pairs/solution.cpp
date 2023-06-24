class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=i+1;j<n;j++){
                if(words[i][0]==words[j][1] && words[i][1]==words[j][0]){
                    c++;
                }
            }
            ans+=c;
        }
        return ans;
    }
};