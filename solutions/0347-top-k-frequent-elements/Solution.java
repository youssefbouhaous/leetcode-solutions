class Solution {
    record Pair(Integer a, Integer b){}
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        int n = nums.length;
        for(int i =0;i<n;i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
        }
        List<Pair> list = new ArrayList<>();
        for(Integer a : map.keySet()){
            list.add(new Pair(map.get(a),a));
        }
        list.sort((a,b)->{
            return b.a.compareTo(a.a);
        });
        int[] ans = new int[k];
        int i =0;
        while(i<k){
            ans[i]=list.get(i++).b();
        }
        return ans;
    }
}