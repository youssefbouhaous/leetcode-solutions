class Solution {
    public int maxOperations(int[] nums, int k) {
        HashMap<Integer,Integer> m = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            m.put(nums[i],m.getOrDefault(nums[i],0)+1);
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            if(m.getOrDefault(nums[i],0)==0)continue;
            int v = m.getOrDefault(k-nums[i],0); 
            if(v!=0){
                if(k==nums[i]*2){
                    if(v>=2){
                        ans++;
                        m.put(nums[i],v-2);
                    }
                }
                else{
                    ans++;
                    m.put(nums[i],m.get(nums[i])-1);
                    m.put(k-nums[i],v-1);
                }
            }
        }
        return ans;
    }
}