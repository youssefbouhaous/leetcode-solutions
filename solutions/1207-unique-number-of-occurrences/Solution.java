class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Arrays.sort(arr);
        HashSet<Integer> oc=new HashSet<>();
        int n = arr.length;
        int c=1;
        for(int i =1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                if(oc.contains(c))return false;
                oc.add(c);
                c = 1;
            }else c ++;
        }
        if(oc.contains(c))return false;
        return true;
    }
}