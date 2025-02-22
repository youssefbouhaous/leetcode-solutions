class Solution {
public:
    int generateKey(int a, int b, int c) {
        int ans=0;
        int i=1;
        while(a|b|c){
            ans+=i*(min({a%10,b%10,c%10}));
            a/=10;
            b/=10;
            c/=10;
            i*=10;
        }
        return ans;
    }
};