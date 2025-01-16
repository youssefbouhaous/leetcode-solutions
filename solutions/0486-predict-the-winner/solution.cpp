class Solution {
    int dp[21][21][2];
    long long int score(vector<int>&nums,int l,int r,bool p1){
        if(l>r)return 0;
        if(dp[l][r][p1]!=-1)return dp[l][r][p1];
        if(p1){
            return dp[l][r][p1]=max(nums[l]+score(nums,l+1,r,false),nums[r]+score(nums,l,r-1,false));
        }
        else{
            return dp[l][r][p1]=min(-nums[l]+score(nums,l+1,r,true),-nums[r]+score(nums,l,r-1,true));
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        for(int i=0;i<21;i++)for(int j=0;j<21;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
        return score(nums,0,nums.size()-1,true)>=0;
    }
};