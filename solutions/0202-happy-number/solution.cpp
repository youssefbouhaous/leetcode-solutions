class Solution {
public:
    map<int,bool>d;
    bool isHappy(int n) {
        if(d[n]){
            return false;
        }
        if(n==1){
            return true;
        }
        d[n]=true;
        int s=0;
        while(n){
            s+=(n%10)*(n%10);
            n/=10;
        }
        return isHappy(s);
    }
};