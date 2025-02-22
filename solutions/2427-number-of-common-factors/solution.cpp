class Solution {
public:
    int commonFactors(int a, int b) {
        int g=gcd(a,b);
        int ans=1;
        for(int i=2;i<=g;i++){
            if(g%i==0)ans++;
        }
        return ans;
    }
};