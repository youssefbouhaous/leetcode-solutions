class Solution {
    public boolean increasingTriplet(int[] nums) {
        List<Integer> st = new ArrayList<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            int m = st.size();
            if(st.isEmpty() || (st.get(m-1)<nums[i]&&m<3)){
                st.add(nums[i]);
                continue;
            }
            boolean fl = false;
            while(m>0 && st.get(m-1)>nums[i]){
                m--;
                fl=true;
            }
            for(Integer x:st){
                if(x==nums[i]){
                    fl=false;
                    break;
                }
            }
            if(fl){
                st.set(m,nums[i]);
            }
        }
        return st.size()==3;
    }
}