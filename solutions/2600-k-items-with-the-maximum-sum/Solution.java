class Solution {
    public int kItemsWithMaximumSum(int o, int z, int n, int k) {
        if(o+z>=k){
            return Math.min(o,k);
        }
        else{
            return o-Math.min(k-o-z,n);
        }
    }
}