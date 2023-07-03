class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max_m=0;
        int c=0;
        if(flowerbed.size()==1){
            if((flowerbed[0]==0 && n<2) || n==0){
                return true;
            }
            return false;
        }
        while(c<flowerbed.size()){
            //cout<<flowerbed[c]<<" ";
            if(c==0 && flowerbed[c]==0  && flowerbed[c+1]==0){
                flowerbed[c]=1;
                max_m++;
            }
            else if(c==flowerbed.size()-1 && flowerbed[c]==0 && flowerbed[c-1]==0){
                flowerbed[c]=1;
                max_m++;
            }
            else if(0<c && c<flowerbed.size()-1 && flowerbed[c]==0 && flowerbed[c+1]==0 && flowerbed[c-1]==0){
                max_m++;
                flowerbed[c]=1;
            }
            c++;
        }
        /*cout<<endl;
        for(auto x:flowerbed){
            cout<<x<<"::";
        }
        cout<<max_m<<endl;*/
        if(n>max_m){
            return false;
        }
        else{
            return true;
        }
    }
};