class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>>ans= new ArrayList<>();
        List<Integer>a=new ArrayList<>();
        a.add(1);
        ans.add(a);
        for(int i=1;i<n;i++){
            List<Integer>tmp=new ArrayList<>();
            tmp.add(1);
            for(int j=1;j<i;j++){
                tmp.add(ans.get(i-1).get(j-1)+ans.get(i-1).get(j));
            }
            tmp.add(1);
            ans.add(tmp);
        }
        return ans;
    }
}