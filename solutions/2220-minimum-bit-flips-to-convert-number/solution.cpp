class Solution {
public:
    int minBitFlips(int a, int b) {
        int ans=0;
        while(a || b){
            if((a&1)!=(b&1)) ans++;
            a/=2;
            b/=2;
        }
        return ans;
    }
};