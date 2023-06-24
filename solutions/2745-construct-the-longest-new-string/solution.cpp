class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=0;
        ans=min(x,y);
        x-=ans;
        y-=ans;
        if(min(x,y)==x){
            if(y!=0){
            return (ans*2+z+1)*2;
            }
            else{
                return (ans*2+z)*2;   
            }
        }
        else{
            if(x!=0){
            return (ans*2+z+1)*2;
            }
            else{
                return (ans*2+z)*2;    
            }
        }
    }
};