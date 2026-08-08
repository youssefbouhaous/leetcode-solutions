class Solution {
    public int[] twoSum(int[] nums, int target) {
        Set<Integer> mp = new HashSet<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            int e = nums[i];
            if(mp.contains(target-e)){
                for(int j=0;j<i;j++){
                    if(target-e==nums[j]){
                        return new int[]{j,i};
                    }
                }
            }
            mp.add(e);
        }
        return null;
    }
}