class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] pre = new int[n+1];
        HashMap<Integer,Integer> st = new HashMap<>();
        st.put(0,1);
        int ans=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
            if(st.get(pre[i+1]-k)!=null)ans+=st.get(pre[i+1]-k);
            st.put(pre[i+1],st.getOrDefault(pre[i+1],0)+1);
            // System.out.println(pre[i+1]+" - ans "+ans+" - "+nums[i]);
        }
        return ans;
    }
}