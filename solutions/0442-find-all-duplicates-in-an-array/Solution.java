class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for(int x:nums){
            x = Math.abs(x);
            if(nums[x-1]<0){
                ans.add(x);
            }else nums[x-1]=-nums[x-1];
        }
        return ans;
    }
}