class Solution {
    public List<List<Integer>> kSmallestPairs(int[] a, int[] b, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        PriorityQueue<ArrayList<Integer>> q = new PriorityQueue<>(
                (aa, bb) -> Integer.compare(
                    aa.get(0) + aa.get(1),bb.get(0) + bb.get(1)  
                ));
        ans.add(new ArrayList<>(Arrays.asList(a[0], b[0])));
        int o = 1;
        while(q.size()<=1000000 && (o<a.length || o<b.length)){
            if(o<b.length)
            for(int i=0;i<=Math.min(o,a.length-1);i++){
                q.add(new ArrayList<>(Arrays.asList(a[i], b[o])));
            }
            if(o<a.length)
            for(int i=0;i<Math.min(o,b.length);i++){
                q.add(new ArrayList<>(Arrays.asList(a[o], b[i])));
            }
            o++;
        }
        k--;
        while(k>0){
            k--;
            ans.add(q.poll());
        }
        return ans;
    }
}