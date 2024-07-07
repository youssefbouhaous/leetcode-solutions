class Solution {
public:
    int numWaterBottles(int b, int x) {
        int e=0;
        int ans=0;
        while(b || (b+e)/x){
            ans+=b;
            int bt=b;
            b=(b+e)/x;
            e=bt+e-x*(b);
        }
        return ans;
    }
};