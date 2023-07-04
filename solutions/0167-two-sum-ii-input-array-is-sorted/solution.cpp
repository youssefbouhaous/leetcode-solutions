class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lp=0;
        int rp=numbers.size()-1;
        while(lp<rp){
            if(numbers[lp]+numbers[rp]==target){
                vector<int>a={lp+1,rp+1};
                return a;
            }
            else if(numbers[lp]+numbers[rp]<target){
                lp++;
            }
            else{
                rp--;
            }
        }
        vector<int>a;
        return a;
    }
};