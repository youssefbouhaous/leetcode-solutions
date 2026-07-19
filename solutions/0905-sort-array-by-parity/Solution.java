class Solution {
    public int[] sortArrayByParity(int[] nums) {
        List<Integer> o =new ArrayList<>();
        for(Integer x:nums)o.add(x);
        o.sort((a,b)->{
            if(a%2==b%2)return a.compareTo(b);
            else if(a%2==0) return -1;
            else return 1;
        });
        int[] ans = new int[nums.length];
        for(int i=0;i<o.size();i++){
            ans[i]=o.get(i);
        }
        return ans;
    }
}