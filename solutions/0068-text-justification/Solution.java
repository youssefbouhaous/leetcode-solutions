class Solution {
    public List<String> fullJustify(String[] w, int m) {
        List<ArrayList<String>> tmp = new ArrayList<>();
        tmp.add(new ArrayList());
        tmp.get(0).add(w[0]);
        int n = w.length;
        int c= w[0].length();
        for(int i=1;i<n;i++){
            if(c+w[i].length()+tmp.get(tmp.size()-1).size()<=m){
                tmp.get(tmp.size()-1).add(w[i]);
                c+=w[i].length();
            }else{
                c=w[i].length();
                tmp.add(new ArrayList());
                tmp.get(tmp.size()-1).add(w[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        int id = 0;
        for(var x:tmp){
            id++;
            if(x.size()==1){
                ans.add(x.get(0)+" ".repeat(m-x.get(0).length()));
            }
            else if(id==tmp.size()){
                StringBuilder o = new StringBuilder();
                for(var p:x){
                    o.append(p+" ");
                }
                o.setLength(o.length()-1);
                // System.out.println(m+" - "+o.length());
                ans.add(o.append(" ".repeat(m-o.length())).toString());
            } 
            else{
                StringBuilder o = new StringBuilder();
                int t = m-x.stream().mapToInt(a->a.length()).sum();
                // System.out.println("t"+t);
                int u = t/(x.size()-1);
                int uo = t%(x.size()-1);
                for(var p:x){
                    o.append(p+" ".repeat(u+(uo-->0?1:0)));
                }
                ans.add(o.toString().strip());
            }
            // System.out.println(ans.get(ans.size()-1));
        }
        return ans;
    }
}