class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int x) {
        int max = Arrays.stream(candies).max().getAsInt();
        List<Boolean> ans = new ArrayList<>();
        for(int i = 0;i<candies.length;i++){
            if(candies[i]+x>=max)ans.add(true);
            else ans.add(false);
        }
        return ans;
    }
}