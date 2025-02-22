class Solution {
public:
    int smallestNumber(int n) {
        int ans=0;
        int i=0;
        while(n){
            ans+=(1<<i);
            n>>=1;
            i++;
        }
        return ans;
    }
};