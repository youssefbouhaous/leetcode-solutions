class Solution {
    public int[] twoSum(int[] arr, int t) {
        int[] ids = new int[4001];
        int n = arr.length;
        for(int i=0;i<n;i++){
            if(ids[t-arr[i]+1000]!=0){
                for(int j=0;j<i;j++){
                    if(t-arr[i]==arr[j]){
                        return new int[]{j+1,i+1};
                    }
                }
            }
            ids[arr[i]+1000]=1;
        }
        return new int[]{-1,-1};
    }
}