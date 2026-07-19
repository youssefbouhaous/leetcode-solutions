class Solution {
    public int[] plusOne(int[] d) {
        List<Integer> tmp = new ArrayList<>();
        for(int x:d)tmp.add(x);
        Collections.reverse(tmp);
        int r = 1;
        int n = tmp.size();
        for(int i=0;i<n;i++){
            if(tmp.get(i)<9){
                tmp.set(i,tmp.get(i)+1);
                r=0;break;
            }
            else{
                tmp.set(i,0);
            }
        }
        if(r==1)tmp.add(1);
        int[] ans = new int[tmp.size()];
        Collections.reverse(tmp);
        for(int i =0;i<tmp.size();i++)ans[i]=tmp.get(i);
        return ans;
    }
}