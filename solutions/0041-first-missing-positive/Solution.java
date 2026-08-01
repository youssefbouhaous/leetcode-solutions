class Solution {
    public int firstMissingPositive(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Set<Integer> s = new HashSet<>();
        for(Integer x : nums){
            if(x>0 && !s.contains(x))list.add(x);
            s.add(x);
        } 
        list.sort((a,b)->a.compareTo(b));
        int cur=1;
        for(Integer x:list){
            if(cur!=x)return cur;
            cur++;
        }
        return cur;
    }
}