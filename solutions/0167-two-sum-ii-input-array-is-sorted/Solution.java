class Solution {
    public int[] twoSum(int[] a, int t) {
        int[] arr= new int[4002];
        int n = a.length;
        for(int i=0;i<n;i++){
            int o = Math.abs(t-a[i]+1000);
            if(arr[o]!=0){
                return new int[]{arr[o],i+1};
            }
            arr[a[i]+1000] = i+1;
        }
        return null;
    }
}