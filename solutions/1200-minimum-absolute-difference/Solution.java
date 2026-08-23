class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(arr);
        int mn = arr[1]-arr[0];
        int i=0;
        int n = arr.length;
        while(i+1<n){
            if(arr[i+1]-arr[i]<mn){
                list=new ArrayList<>();
                mn=arr[i+1]-arr[i];
            }
            if(arr[i+1]-arr[i]==mn)
            list.add(List.of(arr[i],arr[i+1]));
            i++;
        }
        return list;
    }
}