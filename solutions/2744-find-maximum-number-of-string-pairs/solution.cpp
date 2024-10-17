class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    swap(words[j][0],words[j][1]);
                    if(words[i]==words[j]){
                        ans++;
                    }
                    swap(words[j][0],words[j][1]);
                }
            }
        }
        return ans/2;
    }
};