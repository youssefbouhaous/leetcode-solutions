class Solution {
    public int findMin(int[] arr) {
        int ans=arr[0];
        int l=0;
        int r=arr.length-1;
        while(l<=r){
            int m=(l+r)/2;
            if(m!=arr.length-1 && arr[m]>arr[m+1]){
                ans=Math.min(ans,arr[m+1]);
                return ans;
            }
            if(arr[m]>=arr[0]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
}