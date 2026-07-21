class Solution {
    public int[][] insert(int[][] a, int[] b) {
        if(a.length==0){
            return new int[][]{b};
        }
        List<int[]> tmp = new ArrayList<>();
        for(var x:a)tmp.add(x);
        tmp.add(b);
        tmp.sort((x,y)->{
            if(x[0] == y[0]){
                if(x[1]>y[1])return 1;
                return -1;
            }
            if(x[0]>y[0])return 1;
            return -1;
        });
        List<int[]> al = new ArrayList<>();
        int l=0;
        int n = tmp.size();
        while(l<n-1){
            if(tmp.get(l)[1]<tmp.get(l+1)[0]){
                al.add(tmp.get(l));
            }
            else{
                int le = tmp.get(l)[0];
                while(l<n-1 && tmp.get(l)[1]>=tmp.get(l+1)[0]){
                    tmp.get(l+1)[1]=Math.max(tmp.get(l)[1],tmp.get(l+1)[1]);
                    l++;
                }
                int re = tmp.get(l)[1];
                al.add(new int[]{le,re});
                
            }
            l++;
        }
        if(tmp.get(n-1)[0]>al.get(al.size()-1)[1])
        al.add(tmp.get(n-1));
        int[][] ans = new int[al.size()][];
        for(int i=0;i<al.size();i++){
            ans[i]=al.get(i);
        }
        return ans;
    }
}