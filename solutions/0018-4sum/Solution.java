class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>>ans=new ArrayList<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int u=j+1;u<n;u++){
                    int l=u+1;
                    int r=n-1;
                    long o=(long)nums[i]+(long)nums[j]+(long)nums[u];
                    while(l<=r){
                        int m=(l+r)/2;
                        long tmp=o+(long)nums[m];
                        if(tmp>Integer.MAX_VALUE){r=m-1;}
                        if(tmp<Integer.MIN_VALUE){l=m+1;}
                        if( tmp==target){
                            List<Integer>ltmp=new ArrayList<>(List.of(nums[i],nums[j],nums[u],nums[m]));
                            Collections.sort(ltmp);
                            if(!ans.contains(ltmp))ans.add(ltmp);
                            break;
                        }
                        else if(tmp<target) l=m+1;
                        else r=m-1;
                    }
                }
            }
        }
        return ans;
    }
}