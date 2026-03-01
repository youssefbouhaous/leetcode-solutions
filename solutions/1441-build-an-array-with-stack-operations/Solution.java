class Solution {
    public List<String> buildArray(int[] target, int n) {
        int len = target.length;
        int[] t = new int[len];
        List<String> ans = new ArrayList<>();
        for(int i=1,j=0;i<=n && j<len;i++){
            if(target[j] == i){
                j++;
                ans.add("Push");
            }
            else{
                ans.add("Push");
                ans.add("Pop");
            }
        }
        return ans;
    }
}