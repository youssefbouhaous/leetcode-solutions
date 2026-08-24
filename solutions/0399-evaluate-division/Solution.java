class Solution {
    Set<String> st = new HashSet<>();
    Map<String,List<P>> mp = new HashMap<>();
    record P(String b,Double v){}
    Double f(String a,String b){
        if(st.contains(a)||mp.get(a)==null||mp.get(b)==null)return null;
        if(a.equals(b))return 1.0;
        st.add(a);
        for(P x:mp.get(a)){
            if(x.b().equals(b)){
                return x.v();
            }
        }
        for(P x:mp.get(a)){
            if(st.contains(x.b()))continue;
            Double vv =f(x.b(),b);
            if(vv!=null){
                return x.v*vv; 
            }
        }
        return null;
    }
    public double[] calcEquation(List<List<String>> eq, double[] vs, List<List<String>> q) {
        
        int i=0;
        for(List<String> l:eq){
            mp.putIfAbsent(l.get(0),new ArrayList<>());
            mp.get(l.get(0)).add(new P(l.get(1),vs[i]));
            mp.putIfAbsent(l.get(1),new ArrayList<>());
            mp.get(l.get(1)).add(new P(l.get(0),1/vs[i]));
            i++;
        }
        // System.out.println(mp);
        int n = q.size();
        double[] ans = new double[n];
        for(i=0;i<n;i++){
            st = new HashSet<>();
            Double vv =f(q.get(i).get(0),q.get(i).get(1));
            if(vv==null){
                ans[i]=-1;
            }
            else
            ans[i]=vv;
        }
        return ans;
    }
}