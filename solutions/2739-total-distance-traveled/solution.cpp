class Solution {
public:
    int distanceTraveled(int m, int a) {
        int ans=0;
        while(m>0){
            ans+=min(m,5);
            m-=5;
            if(a>0){
                m++;
                a--;
            }
        }
        return ans*10;
    }
};