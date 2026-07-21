class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int x:nums)q.add(x);
        int n=nums.length;
        while(q.size()!=k)q.poll();
        return q.peek();
    }
}