class Solution {
public:
    int minChanges(int n, int k) {
        if(n==k){
            return 0;
        }
        int ans=0;
        while(n || k){
            if((n&1)!=(k&1) && (n&1)==0){
                return -1;
            }
            else if((n&1)!=(k&1)){
                ans++;
            }
            n/=2;
            k/=2;
        }
        return ans;
    }
};