class Solution {
    public List<Integer> getRow(int n) {
        List<Integer>a=new ArrayList<>();
        a.add(1);
        for(int i=1;i<=n;i++){
            List<Integer>tmp=new ArrayList<>();
            tmp.add(1);
            for(int j=1;j<i;j++){
                tmp.add(a.get(j)+a.get(j-1));
            }
            tmp.add(1);
            a=tmp;
        }
        return a;
    }
}