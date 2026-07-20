class Solution {
    public int[][] merge(int[][] arr) {
        Arrays.sort(arr, (a, b) -> {
            int n = Math.min(a.length, b.length);

            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    return Integer.compare(a[i], b[i]);
                }
            }

            return Integer.compare(a.length, b.length);
        });
        int l=0;
        int n = arr.length;
        int r=0;
        List<List<Integer>> ans=new ArrayList<>();
        while(l<n){
            int[] tmp = new int[2];
            tmp[0]=arr[l][0];
            while(l<n-1 && arr[l][1]>=arr[l+1][0]){
                arr[l+1][1]=Math.max(arr[l+1][1],arr[l][1]);
                l++;
            }
            tmp[1]=arr[l][1];
            ans.add(Arrays.asList(tmp[0], tmp[1]));
            l++;
        }
        int[][] an = new int[ans.size()][];
        for(int i=0;i<ans.size();i++){
            // System.out.println(ans.get(i));
            int a=ans.get(i).get(0);
            int b=ans.get(i).get(1);
            an[i] = new int[]{a,b};
        }
        return an;
    }
}