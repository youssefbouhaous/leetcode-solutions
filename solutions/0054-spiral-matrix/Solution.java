class Solution {
    int n;
    int m;
    public boolean valid(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    public List<Integer> spiralOrder(int[][] mat) {
        List<Integer> ans = new ArrayList<>();
        int d=0;
        n = mat.length;
        m = mat[0].length;
        int i = 0;
        int j = 0;
        HashSet<String> st = new HashSet<>();
        while(ans.size()<n*m){
            ans.add(mat[i][j]);
            st.add(i+"-"+j);
            if(d==0){
                j++;
                if(j>=m || st.contains(i+"-"+j)){
                    j--;i++;d=1;
                }
            }else if(d==1){
                i++;
                if(i>=n || st.contains(i+"-"+j)){
                    i--;j--;d=2;
                }
            }else if(d==2){
                j--;
                if(j<0 || st.contains(i+"-"+j)){
                    j++;i--;d=3;
                }
            }else if(d==3){
                i--;
                if(i<0 || st.contains(i+"-"+j)){
                    i++;j++;d=0;
                }
            }
        }
        return ans;
    }
}