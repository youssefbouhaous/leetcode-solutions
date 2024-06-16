class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==t){
                return 0;
            }
            return -1;
        }
        int l=0;
        int r=n-1;
        int m=0;
        while(l<=r){
            m=(l+r)/2;
            if(m!=n-1 && nums[m]>nums[m+1]){
                break;
            }
            if(nums[m]>=nums[0]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        l=m+1;
        r=n-1;
        while(l<=r){
            int mm=(l+r)/2;
            if(nums[mm]==t){
                return mm;
            }
            if(nums[mm]<t){
                l=mm+1;
            }
            else{
                r=mm-1;
            }
        }
        cout<<m;
        l=0;
        r=m;
        while(l<=r){
            int mm=(l+r)/2;
            if(nums[mm]==t){
                return mm;
            }
            if(nums[mm]<t){
                l=mm+1;
            }
            else{
                r=mm-1;
            }
        }
        return -1;
    }
};