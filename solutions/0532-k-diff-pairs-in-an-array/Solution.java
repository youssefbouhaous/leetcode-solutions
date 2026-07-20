class Solution {
    public class Pair{
        int a,b;
        Pair(int a,int b){
            this.a=Math.max(a,b);
            this.b=Math.min(a,b);
        }
         @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return a == p.a && b == p.b;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a+"-"+ b);
        }
    }
    public int findPairs(int[] nums, int k) {
        Set<Pair> st = new HashSet<>();
        Set<Integer> s = new HashSet<>();
        int n = nums.length;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s.contains(k+nums[i])){
                if(!st.contains(new Pair(nums[i],k+nums[i]))){
                    ans++;
                }
                st.add(new Pair(nums[i],k+nums[i]));
            }
            if(s.contains(nums[i]-k)){
                if(!st.contains(new Pair(nums[i],-k+nums[i]))){
                    ans++;
                }
                st.add(new Pair(nums[i],-k+nums[i]));
            }
            s.add(nums[i]);
        }
        return ans;
    }
}