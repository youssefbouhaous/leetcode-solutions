class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                long long int cp=0;
                long long int cm=0;
                char tmp=s[i];
                while(tmp!=t[i]){
                    cp+=(long long int)nextCost[tmp-'a'];
                    if(tmp=='z'){
                        tmp='a';
                    }
                    else{
                        tmp++;
                    }
                }
                tmp=s[i];
                while(tmp!=t[i]){
                    cm+=(long long int)previousCost[tmp-'a'];
                    if(tmp=='a'){
                        tmp='z';
                    }
                    else{
                        tmp--;
                    }
                }
                ans+=min(cp,cm);
            }
        }
        return ans;
    }
};