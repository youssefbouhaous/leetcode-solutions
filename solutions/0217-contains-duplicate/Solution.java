class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;
        HashSet<Integer> st = new HashSet<>();
        for(int i =0;i<n;i++){
            if(st.contains(nums[i]))return true;
            st.add(nums[i]);
        }
        return false;
    }
}