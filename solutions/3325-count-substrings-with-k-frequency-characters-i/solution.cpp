class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            bool f=false;
            for(int j=i;j<n;j++){
                mp[s[j]-'a']++;
                if(mp[s[j]-'a']>=k){
                    f=true;
                }
                if(f){
                    ans++;
                }
            }
        }
        return ans;
    }
};