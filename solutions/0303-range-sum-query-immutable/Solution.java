class NumArray {
    private int[] pre;
    public NumArray(int[] nums) {
        int n = nums.length;
        pre = new int[n+1];
        for(int i=0;i<n;i++){
            pre[i+1] = nums[i] + pre[i];
        }
    }
    
    public int sumRange(int left, int right) {
        return pre[right+1]-pre[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */