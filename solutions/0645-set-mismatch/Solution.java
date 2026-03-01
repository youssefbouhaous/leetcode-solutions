class Solution {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int sum = nums[0];
        int n = nums.length;
        int duplicate = 0;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                duplicate = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return new int[]{duplicate , n*(n+1)/2 - sum};
    }
}