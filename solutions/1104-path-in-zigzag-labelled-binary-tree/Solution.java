class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> ans = new ArrayList<>();
        ans.add(label);
        while(label>1){
            int x = 0;
            while(label/(2<<(x+1))>=1){
                x++;
            }
            int p = label/2;
            int[] level = new int[(2<<(x))-(2<<(x-1))];
            int base = (2<<(x-1));
            int ba = base;
            for(int i=0;i<level.length;i++){
                level[i]=base;
                base++;
            }
            int[] arr = level;
            for (int i = 0; i < arr.length / 2; i++) {
                int temp = arr[i];
                arr[i] = arr[arr.length - 1 - i];
                arr[arr.length - 1 - i] = temp;
            }
            ans.add(level[p-ba]);
            label=level[p-ba];
        }
        ans.remove(ans.size() - 1);
        ans.add(1);
        Collections.reverse(ans);
        return ans;
    }
}