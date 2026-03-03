class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] ans = prices.clone();
        Stack<int[]> stack = new Stack<>();
        for(int i=0;i<n;i++){
            if(stack.isEmpty()){
                stack.push(new int[]{prices[i],i});
                continue;
            }
            while(!stack.isEmpty() && prices[i] <= stack.peek()[0]){
                ans[stack.peek()[1]] -= prices[i];
                stack.pop();
            }
            stack.push(new int[]{prices[i],i});
        }
        return ans;
    }
}