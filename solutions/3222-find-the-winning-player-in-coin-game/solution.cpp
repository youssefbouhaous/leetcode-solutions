class Solution {
public:
    string losingPlayer(int x, int y) {
        int t=0;
        while(x>=1 && y>=4){
            x--;
            y-=4;
            t++;
        }
        if(t%2==0){
            return "Bob";
        }
        return "Alice";
    }
};