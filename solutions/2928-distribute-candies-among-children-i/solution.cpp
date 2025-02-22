class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans=0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=min(n-i,limit);j++){
                for(int u=0;u<=min(n-i-j,limit);u++){
                    if(u+i+j==n)ans++;
                }
            }
        }
        return ans;
    }
};