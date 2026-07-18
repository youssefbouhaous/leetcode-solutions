class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        ans.add(a);ans.add(b);
        int n=nums1.length;
        int m=nums2.length;
        for(int i=0;i<n;i++){
            boolean f = false;
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    f=true;break;}
            }
            if(f==false && !a.contains(nums1[i])){
                a.add(nums1[i]);
            }
        }
        for(int i=0;i<m;i++){
            boolean f = false;
            for(int j=0;j<n;j++){
                if(nums2[i]==nums1[j]){
                    f=true;break;}
            }
            if(f==false && !b.contains(nums2[i])){
                b.add(nums2[i]);
            }
        }
        return ans;
    }
}