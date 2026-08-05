class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        int n=nums.length;
        a.add(nums[0]);
        if(n>1){
            b.add(nums[1]);
            for(int i=2;i<n;i++){
                if(a.get(a.size()-1)>b.get(b.size()-1)){
                    a.add(nums[i]);
                }else b.add(nums[i]);
            }
        }
        for(Integer x:b)a.add(x);
        int[] ans = new int[a.size()];
        for(int i=0;i<n;i++)ans[i]=a.get(i);
        
        return ans;
    }
}