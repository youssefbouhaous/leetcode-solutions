class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long o=1;
        while(o<x){
            o*=10;
        }
        if(x/o==0){
            o/=10;
        }
        while(x){
            if(x%10!=x/o){
                return false;
            }
            int r=x/o;
            x-=r*o;
            x/=10;
            o/=100;
        }
        return true;
    }
};