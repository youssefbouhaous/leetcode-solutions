class Solution {
    boolean vis[]=new boolean[201*201];
    public void dfs(Integer x,Map<Integer,List<Integer>> map){
        vis[x]=true;
        for(Integer to:map.get(x)){
            if(!vis[to]){
                vis[to]=true;
                dfs(to,map);
            }
        }
    }
    public int findCircleNum(int[][] c) {
        Map<Integer,List<Integer>>map=new HashMap<>();
        int n=c.length;
        for(int i=1;i<=n;i++){
            List<Integer> l=new ArrayList<>();
            map.put(i,l);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(c[i-1][j-1]==1){
                    map.get(i).add(j);
                    map.get(j).add(i);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,map);
                ans++;
            }
        }
        return ans;
    }
}