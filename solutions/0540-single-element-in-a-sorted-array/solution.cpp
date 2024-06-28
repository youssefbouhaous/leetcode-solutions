class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n=nums.size();
        int l=0;
        int r=nums.size()-1;
        int m=(l+r)/2;
        while(l<=r){
            m=(l+r)/2;
            if(m==n-1){
                if(nums[m]!=nums[m-1])
                return nums[m];
                else
                r=m-1;
            }
            else if(m==0){
                if(nums[0]!=nums[1])
                return nums[0];
                else
                l=m+1;
            }
            else{
                if(nums[m]!=nums[m+1] && nums[m]!=nums[m-1]){
                    return nums[m];
                }
                else{
                    if((m%2==0 && nums[m]==nums[m+1]) || (m%2==1 && nums[m]==nums[m-1])){
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
            }
            //cout<<"m"<<m<<" nm"<<nums[m]<<endl;
        }
        return nums[m];
    }
};