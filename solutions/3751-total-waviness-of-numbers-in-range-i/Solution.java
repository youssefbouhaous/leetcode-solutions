class Solution {
    int cal(int a){
        String r = ""+a;
        int n = r.length();
        int s = 0;
        for(int i=1;i<n-1;i++){
            if(r.charAt(i)>r.charAt(i-1) && r.charAt(i)>r.charAt(i+1))s++;
            if(r.charAt(i)<r.charAt(i-1) && r.charAt(i)<r.charAt(i+1))s++;
        }
        return s;
    }
    public int totalWaviness(int a, int b) {
        int s=0;
        for(int i=a;i<=b;i++)s+=cal(i);
        return s;
    }
}