class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1){
            return 1;
        }
        else if(x==0){
            return 0;
        }
        double res=1;
        int b=abs(n);
        while(b>0){
            if(b&1){
                res = res*x;
            }
            x=x*x;
            b>>=1;
        }
        if(n<0){
            res=1/res;
        }
        return res;
    }
};