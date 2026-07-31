class Solution {
    public int[] twoSum(int[] nums, int target) {
        Set<Integer> st = new HashSet<>();
        st.add(nums[0]);
        int n = nums.length;
        for(int i=1;i<n;i++){
            if(st.contains(target-nums[i])){
                for(int j=0;j<i;j++){
                    if(nums[j]==target-nums[i]){
                        return new int[]{j,i};
                    }
                }
            }
            st.add(nums[i]);
        }
        return null;
    }
}