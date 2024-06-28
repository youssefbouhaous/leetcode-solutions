class Solution {
public:
    int arrangeCoins(int n) {
        long int l=0;
        long r=n;
        long sol=1;
        while(l<=r){
            long m=(l+r)/2;
            if(m*(m+1)/2<=n){
                sol=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return sol;
    }
};