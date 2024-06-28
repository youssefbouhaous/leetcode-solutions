class Solution {
public:
    bool isPerfectSquare(int num) {
        long long  int l=1;
        long long int r=num;
        while(l<=r){
            long long int m=(l+r)/2;
            if(m*m==num){
                return true;
            }
            else if(m*m<num){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return false;
    }
};