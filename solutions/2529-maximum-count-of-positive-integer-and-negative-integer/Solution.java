class Solution {
    public int maximumCount(int[] n) {
        List<Integer> nums = Arrays.stream(n)
                            .parallel()    
                            .boxed()        
                            .collect(Collectors.toList());
        return (int)Math.max(
            nums.stream().parallel().filter(a->(a>0)).count()
            ,nums.stream().parallel().filter(a->(a<0)).count()
        );
    }
}