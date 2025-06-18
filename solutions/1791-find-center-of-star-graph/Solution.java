class Solution {
    public int findCenter(int[][] e) {
        Map<Integer,Integer> st=new HashMap<>();
        int n=e.length;
        for(int i=0;i<n;i++){
            st.put(e[i][0],st.getOrDefault(e[i][0],0)+1);
            st.put(e[i][1],st.getOrDefault(e[i][1],0)+1);
            //System.out.println(st);
            if(st.get(e[i][0])==n)return e[i][0];
            if(st.get(e[i][1])==n)return e[i][1];
        }
        return 1;
    }
}