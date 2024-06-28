class Solution {
public:
    int mySqrt(int x) {
        long l=0;
        long r=x;
        long m=(l+r)/2;
        while(l<=r){
            m=(l+r)/2;
            if(m*m==x){
                return m;
            }
            else if(m*m<x){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return (l+r-1)/2;
    }
};