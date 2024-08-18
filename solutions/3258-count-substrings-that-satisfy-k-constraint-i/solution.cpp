class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int o=0;
            int z=0;
            for(int j=i;j<n;j++){
                if(s[j]=='0'){
                    z++;
                }
                else{
                    o++;
                }
                if(o<=k || z<=k){
                    ans++;
                }
            }
        }
        return ans;
    }
};