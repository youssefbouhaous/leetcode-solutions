class Solution {
    public int[] twoSum(int[] a, int t) {
        int l =0;
        int n=a.length;
        int r=n-1;
        while(l<r){
            int o = a[l]+a[r];
            if(o==t){
                return new int[]{l+1,r+1};
            }
            else if(o<t) l++;
            else r--;
        }
        return null;
    }
}