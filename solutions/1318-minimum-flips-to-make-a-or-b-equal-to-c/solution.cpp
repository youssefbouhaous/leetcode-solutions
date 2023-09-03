class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        int d=a|b;
        while(c>0 || a>0 || b>0){
            if((c&1)==1 && (a&1)+(b&1)==0){
                ans++;
            }
            if((c&1)==0 && (a&1)+(b&1)==2){
                ans+=2;
            }
            if((c&1)==0 && (a&1)+(b&1)==1){
                ans++;
            }
            c=(c>>1);
            a=(a>>1);
            b=(b>>1);
        }
        return ans;
    }
};