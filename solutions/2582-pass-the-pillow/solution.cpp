class Solution {
public:
    int passThePillow(int n, int time) {
        if(n==1){
            return 1;
        }
        int a=1;
        int d=1;
        while(time){
            time--;
            a+=d;
            if(a>n){
                a=n-1;
                d=-1;
            }
            if(a<1){
                a=2;
                d=1;
            }

        }
        return a;
    }
};