class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        Map<Integer,Integer> st = new HashMap<>();
        int cur = 0;
        st.put(0,1);
        int n = nums.length;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(st.get(cur-k)!=null){
                ans+=st.get(cur-k);
            }
            st.put(cur,st.getOrDefault(cur,0)+1);
        }
        return ans;
    }
}