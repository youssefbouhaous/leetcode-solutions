class Solution {
    public int jump(int[] arr) {
        int n=arr.length;
        int[] d=new int[n];
        Arrays.fill(d,n+1);
        d[0]=0;
        for(int i=0;i<n;i++){
            if(d[i]!=n+1){
                for(int j=i+1;j<=Math.min(arr[i]+i,n-1);j++){
                    d[j]=Math.min(d[j],d[i]+1);
                }
            }
        }
        return d[n-1];
    }
}