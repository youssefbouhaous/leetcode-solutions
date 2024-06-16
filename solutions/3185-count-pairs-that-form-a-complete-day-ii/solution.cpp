class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int,int>d;
        long long ans=0;
        for(auto x:hours){
            if(x%24==0){
            ans+=d[x%24];
            }
            else{
                ans+=d[24-x%24];
            }
            d[x%24]++;
        }
        return ans;
    }
};