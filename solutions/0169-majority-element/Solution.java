class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> d= new HashMap<>();
        int ans=nums[0];
        int m=0;
        for(int i=0;i<nums.length;i++){
            if(d.containsKey(nums[i])){
            d.put(nums[i],d.get(nums[i])+1);
            }
            else{
                d.put(nums[i],1);
            }
            if(d.get(nums[i])>nums.length/2){
                ans=nums[i];
            }
        }
        return ans;
    }
}