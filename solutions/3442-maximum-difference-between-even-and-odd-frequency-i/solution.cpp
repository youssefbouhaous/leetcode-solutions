class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26);
        for(auto x:s){
            freq[x-'a']++;
        }
        int mx=INT_MIN;
        for(auto x:s){
            for(auto y:s){
                if(freq[x-'a']%2!=freq[y-'a']%2){
                    if(freq[x-'a']%2==1)
                    mx=max(mx,freq[x-'a']-freq[y-'a']);
                    else
                        mx=max(mx,-freq[x-'a']+freq[y-'a']);
                }
            }
        }
        return mx;
    }
};