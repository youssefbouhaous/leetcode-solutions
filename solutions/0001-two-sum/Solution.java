class Solution {
    public int[] twoSum(int[] nums, int t) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int n = nums.length;
        for(int i =0;i<n;i++){
            map.put(nums[i],i);
        }
        for(int i =0;i<n;i++){
            if(map.containsKey(t-nums[i])){
                if(nums[i] == t-nums[i]){
                    if(map.get(nums[i])!=i)return new int[]{i,map.get(nums[i])};
                }
                else return new int[]{i,map.get(t-nums[i])};
            }
        }
        return null;
        
    }
}