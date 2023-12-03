class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>b=flowerbed;
        if(n==0){
            return true;
        }
        if(b.size()==1){
            if(b[0]==0 || n==0)
            return true;
        }
        if(b[0]==0 && b[1]==0){
            b[0]=1;
            n--;
        }
        for(int i=1;i<b.size()-1;i++){
            if(n==0){
                break;
            }
            if(b[i]==0 && b[i-1]==0 && b[i+1]==0){
                b[i]=1;
                n--;
            }
            
        }
        if(n==1 && b[b.size()-1]==0 && b[b.size()-2]==0){
            return true;
        }
        return n==0;
    }
};