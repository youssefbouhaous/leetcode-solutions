class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> stack = new Stack<>();
        int[] ans = new int[n];
        String[] s = logs.get(0).split(":");
        stack.push(Integer.parseInt(s[0]));
        int i = 1, time = Integer.parseInt(s[2]);
        while(i < logs.size()){
            s = logs.get(i).split(":");
            if(!stack.isEmpty())
            ans[stack.peek()]+=Integer.parseInt(s[2])-time;
            time = Integer.parseInt(s[2]);
            if(s[1].equals("start")) stack.push(Integer.parseInt(s[0]));
            else{
                ans[Integer.parseInt(s[0])]++;
                time++;
                stack.pop();
            }
            i++;
        }
        return ans;
    }
}