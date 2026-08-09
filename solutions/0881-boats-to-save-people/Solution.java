class Solution {
    public int numRescueBoats(int[] p, int limit) {
        Arrays.sort(p);
        int n = p.length;
        int ans = 0;
        int c = 0;
        int l = 0;
        int r = n-1;
        int cnt = 0;
        while(l<=r){
            if(l==r){
                ans++;break;
            }else{
                if(p[l]+p[r]<=limit){
                    ans++;
                    l++;r--;
                }else{
                    ans++;r--;
                }
            }
        }
        return ans;
    }
}