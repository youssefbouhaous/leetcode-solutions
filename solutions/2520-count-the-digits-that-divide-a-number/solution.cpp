class Solution {
public:
    int countDigits(int num) {
        int ans=0;
        int t=num;
        while(num){
            if(t%(num%10)==0){
                ans++;
            }
            num/=10;
        }
        return ans;
    }
};