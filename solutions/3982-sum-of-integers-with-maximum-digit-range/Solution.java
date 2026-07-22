class Solution {
    public int maxDigitRange(int[] nums) {
        int mx = 0;
        int ans = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            int s = 10;
            int x = 0;
            String tmp = nums[i]+"";
            for(int j=0;j<tmp.length();j++){
                s = Math.min(s,tmp.charAt(j)-'0');
                x = Math.max(x,tmp.charAt(j)-'0');
            }
            if(mx<x-s){
                mx=x-s;
                ans  = nums[i];
            }
            else if(mx==x-s){
                ans+=nums[i];
            }
        }
        return ans;
    }
}