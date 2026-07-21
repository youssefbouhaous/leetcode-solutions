class Solution {
    public List<String> fullJustify(String[] w, int m) {
        List<String> ans = new ArrayList<>();
        // int i=0;
        int n = w.length;
        // int c=0;
        List<List<String>> tmp = new ArrayList<>();
        int c=w[0].length();
        tmp.add(new ArrayList<>());
        tmp.get(tmp.size()-1).add(w[0]);
        for(int i=1;i<n;i++){
            if(w[i].length()+c+1<=m){
                tmp.get(tmp.size()-1).add(w[i]);
                c=w[i].length()+c+1;
            }else{
                c=w[i].length();
                tmp.add(new ArrayList<>());
                tmp.get(tmp.size()-1).add(w[i]);
                
            }
        }
        int cc=0;
        int nn=tmp.size();
        for(var x:tmp){
            int t = x.size();
            cc++;
            if(t==1){
                ans.add(x.get(0)+" ".repeat(m-x.get(0).length()));
                continue;
            }
            if(cc==nn){
                StringBuilder tm = new StringBuilder();
                int ttt=1;
                for(var y:x){
                    tm.append(y+" ");
                    ttt+=y.length();
                }
                // System.out.println(tm+" - "+ttt);
                if(tm.length()>m){
                    ans.add(tm.toString().substring(0,tm.length()-1));break;    
                }
                tm.append(" ".repeat(m-tm.length()));
                ans.add(tm.toString());
                    
                break;
            }
            t=0;
            for(var y:x)t+=y.length();
            int r=(m-t)/(x.size()-1);
            int rr = (m-t)%(x.size()-1);
            StringBuilder tm = new StringBuilder();
            for(var y:x){
                tm.append(y+" ".repeat(r+(rr>0?1:0)));
                rr--;
            }
            ans.add(tm.toString().strip());
            // System.out.println(tm+" -+_ "+cc);
        }
        return ans;
    }
}