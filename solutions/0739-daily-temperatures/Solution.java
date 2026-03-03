class Solution {
    public int[] dailyTemperatures(int[] t) {
        Stack<int[]> stack = new Stack<>();
        int n = t.length;
        int[] ans = new int[n];
        for(int i=0;i<n;i++){
            if(stack.isEmpty()){
                stack.push(new int[]{t[i],i});
                continue;
            }
            while(!stack.isEmpty() && t[i]>stack.peek()[0]){
                ans[stack.peek()[1]] = i-stack.peek()[1];
                stack.pop();
            }
            stack.push(new int[]{t[i],i});
        }
        return ans;
    }
}