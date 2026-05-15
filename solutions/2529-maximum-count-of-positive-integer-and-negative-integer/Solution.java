class Solution {
    public int maximumCount(int[] n) {
        List<Integer> nums = Arrays.stream(n)    
                            .boxed()        
                            .collect(Collectors.toList());
        return (int)Math.max(
            nums.stream().filter(a->(a>0)).count()
            ,nums.stream().filter(a->(a<0)).count()
        );
    }
}