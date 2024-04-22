class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1){
            return 1;
        }
        else if(x==0){
            return 0;
        }
        double ans=1;
        int b=abs(n);
        while(b>0){
            if (b & 1)
                ans = ans * x;
            x = x * x;
            b >>= 1;
        }
        if(n<0){
            ans=1/ans;
        }
        return ans;
    }
};