class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++) mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        int[] ans = new int[]{-1,-1};
        for(int i=0;i<n;i++){
            if(mp.get(target-nums[i])!=null){
                if(target == nums[i]*2){
                    if(mp.get(nums[i])<2)continue;
                    else{
                        ans[0]=i;
                        for(int j=i+1;j<n;j++){
                            if(nums[j]==nums[i]){
                            ans[1]=j;break;}
                        }
                        return ans;
                    }
                }
                else{
                    ans[0]=i;
                    for(int j=i+1;j<n;j++){
                            if(nums[j]==target-nums[i]){
                            ans[1]=j;break;
                            }
                        }
                        return ans;
                }
            }
        }
        return ans;
    }
}