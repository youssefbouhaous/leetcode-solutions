class Solution {
public:
    bool canAliceWin(int n) {
        int p=10;
        int turn=0;
        while(n>=p){
            n-=p;
            turn++;
            p--;
            if(n<p){
                break;
            }
            n-=p;
            p--;
            turn++;
            
        }
        return turn%2!=0;
    }
};