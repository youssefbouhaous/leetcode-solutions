class Solution {
    public int firstMissingPositive(int[] nums) {
        List<Integer> l = new ArrayList<>();
        Arrays.sort(nums);
        for(int i:nums){
            if(i>0 && (l.size()==0 || i!=l.get(l.size()-1)))
            l.add(i);
        }
        if(l.size()==0)return 1;
        Collections.sort(l);
        for(int i=1;i<l.get(l.size()-1);i++){
            if(i!=l.get(i-1))return i;
        }
        return l.get(l.size()-1)+1;
    }
}