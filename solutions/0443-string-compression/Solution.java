class Solution {
    public int compress(char[] chars) {
        int c = 1;
        int n = chars.length;
        
        if(n==1)return 1;
        List<String> tmp = new ArrayList<>();
        Deque<Integer> q = new ArrayDeque<>();
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                c++;
            }
            else{
                tmp.add(""+chars[i-1]);
                q.addLast(c);
                c=1;
            }
        }
        tmp.add(chars[n-1]+"");
        q.addLast(c);
        int j=0;
        int nn=0;
        for(int i=0;i<tmp.size();i++){
            char o = tmp.get(i).charAt(0);
            chars[j++]=o;
            nn++;
            int k=0;
            int kn = q.pollFirst();
            if(kn<2)continue;
            String tkn = "" +kn;
            while(k<tkn.length()){
                nn++;
                chars[j++]=tkn.charAt(k++);
            }
        }
        return nn;
    }
}