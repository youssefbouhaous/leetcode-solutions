class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        HashMap map = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            map.put(nums[i],1);
        }
        for(int i =1;i<=n;i++){
            if(map.containsKey(i) == false){
                ans.add(i);
            }
        }
        return ans;
    }
}