class Solution {
    public int majorityElement(int[] nums) {
        int maj = nums[0];
        int cnt = 1;
        int n = nums.length;
        for(int i=1;i<n;i++){
            if(cnt==0){
                maj=nums[i];
                cnt++;
            }
            else if(maj == nums[i])cnt++;
            else cnt--;
        }
        return maj;
    }
}