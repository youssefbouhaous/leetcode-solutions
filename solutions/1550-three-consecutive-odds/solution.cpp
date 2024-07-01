class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c=0;
        for(auto x:arr){
            if(x%2){
                c++;
                if(c==3){
                    return true;
                }
            }
            else{
                c=0;
            }
        }
        return false;
    }
};