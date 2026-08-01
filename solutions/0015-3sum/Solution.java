class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;        
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l = i+1;
            int r = n-1;
            while(l<r){
                int o = nums[l]+nums[r]+nums[i];
                if(o==0){
                    ans.add(List.of(nums[i],nums[l],nums[r]));
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(r>l && nums[r]==nums[r+1])r--;
                }
                else if(o<0)l++;
                else r--;
            }
        }
        return ans;
    }
}