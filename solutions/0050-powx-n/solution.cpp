class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        while(n>0){
            if(n&1){
                ans=x*ans;
            }
            x*=x;
            n>>=1;
        }
        if(n<0){
            x=1/(x);
            n=abs(n);
            while(n>0){
                if(n&1){
                    ans=ans*x;
                }
                x*=x;
                n>>=1;
            }
        }
        return ans;
    }
};