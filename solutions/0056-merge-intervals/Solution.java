class Solution {
    public int[][] merge(int[][] l) {
        Arrays.sort(l,(a,b)->{
            if(a[0]==b[0])return Integer.compare(a[1],b[1]);
            return Integer.compare(a[0],b[0]);
        });
        List<int[]> tmp = new ArrayList<>();
        int n = l.length;
        int i=0;
        while(i<n){
            int a = l[i][0];
            int b=l[i][1];
            i++;
            while(i<n && b>=l[i][0]){
                b=Math.max(b,l[i][1]);i++;
            }
            tmp.add(new int[]{a,b});
        }
        int[][] ans = new int[tmp.size()][];
        for(int j=0;j<tmp.size();j++){
            ans[j]=tmp.get(j);
        }
        return ans;
    }
}