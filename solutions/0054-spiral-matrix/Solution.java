class Solution {
    int n;
    int m;

    boolean valid(int i,int j){
        return i<n && i>=0 && j<m && j>=0;
    }
    public List<Integer> spiralOrder(int[][] mat) {
        int i=0;
        int j=0;
        n = mat.length;
        m = mat[0].length;
        Set<String> vis = new HashSet<>();
        int d=0;
        List<Integer> ans = new ArrayList<>();
        while(ans.size()<n*m){
            String hash = i+"-"+j;
            if(valid(i,j) && !vis.contains(hash)){
                ans.add(mat[i][j]);}
            
            vis.add(hash);
            if(d==0){
                j++;
                hash = i+"-"+j;
                if(!valid(i,j) || vis.contains(hash)){
                    d=1;
                    j--;
                }
            }
            else if(d==1){
                i++;
                hash = i+"-"+j;
                if(!valid(i,j) || vis.contains(hash)){
                    d=2;
                    i--;
                }
            }
            else if(d==2){
                j--;
                hash = i+"-"+j;
                if(!valid(i,j) || vis.contains(hash)){
                    d=3;
                    j++;
                }
            }
            if(d==3){
                i--;
                hash = i+"-"+j;
                if(!valid(i,j) || vis.contains(hash)){
                    d=0;
                    i++;
                }
            }
        }
        return ans;
    }
}