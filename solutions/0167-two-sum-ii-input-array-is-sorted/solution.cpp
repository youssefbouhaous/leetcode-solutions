class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans(2);
        int l=0;
        int r=numbers.size()-1;
        int s=0;
        while(l<r){
            s=numbers[l]+numbers[r];
            if(s==target){
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            }
            else if(s<target){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};