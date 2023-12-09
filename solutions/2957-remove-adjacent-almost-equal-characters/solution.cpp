class Solution {
public:
    int removeAlmostEqualCharacters(string w) {
        int ans=0;
        int tmp=1;
        for(int i=1;i<w.size();i++){
            if(abs(w[i]-w[i-1])<2){
                tmp++;
            }
            else{
                ans+=tmp/2;
                tmp=1;
            }
        }
        ans+=tmp/2;
        return ans;
    }
};