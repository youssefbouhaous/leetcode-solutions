class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        map<int,int>d;
        int ans=0;
        int n=hours.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((hours[i]+hours[j])%24==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};