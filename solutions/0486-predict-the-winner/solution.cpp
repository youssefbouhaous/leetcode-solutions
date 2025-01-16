class Solution {
    long long int score(vector<int>&nums,int l,int r,bool p1){
        if(l>r)return 0;
        if(p1){
            return max(nums[l]+score(nums,l+1,r,false),nums[r]+score(nums,l,r-1,false));
        }
        else{
            return min(-nums[l]+score(nums,l+1,r,true),-nums[r]+score(nums,l,r-1,true));
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return score(nums,0,nums.size()-1,true)>=0;
    }
};