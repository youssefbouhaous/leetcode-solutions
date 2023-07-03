class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=*max_element(candies.begin(),candies.end());
        vector<bool>ans;
        for(int x:candies){
            if(x+extraCandies>=m){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};