class Solution {
    public int largestRectangleArea(int[] h) {
        int n = h.length;
        int ans = 0;
        Stack<int[]> stack = new Stack<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for(int i=0 ; i<n ; i++ ){
            if(stack.isEmpty()){
                stack.push(new int[]{h[i],i});
                continue;
            }
            if(h[i]>stack.peek()[0]){
                left[i] = stack.peek()[1];
            }
            else{
                while(!stack.isEmpty() && h[i] <= stack.peek()[0]){
                    stack.pop();
                }
            }
            if(!stack.isEmpty()){
                left[i] = stack.peek()[1];
            }
            stack.push(new int[]{h[i],i});
        }
        stack.clear();
        for(int i=n-1;i>-1;i--){
            if(stack.isEmpty()){
                stack.push(new int[]{h[i],i});
                continue;
            }
            if(h[i]>stack.peek()[0]){
                right[i] = stack.peek()[1];
            }
            else{
                while(!stack.isEmpty() && h[i] <= stack.peek()[0]){
                    stack.pop();
                }
            }
            if(!stack.isEmpty()){
                right[i] = stack.peek()[1];
            }
            stack.push(new int[]{h[i],i});
        }
        for(int i=0;i<n;i++){
            int w = right[i]-left[i]-1;
            ans = Math.max(ans,w*h[i]);           
        }
        return ans;
    }
}