class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int ans=0;
        int tans=0;
        int c=1;
        bool f=false;
        int tr=red;
        int tb=blue;
        while(red>=0 && blue>=0){
            if(f && red>=c){
                red-=c;
                c++;
                ans++;
                f=!f;
            }
            else if(!f && blue>=c){
                blue-=c;
                c++;
                ans++;
                f=!f;
            }
            else{
                break;
            }
        }
        red=tr;
        blue=tb;
        f=true;
        c=1;
        while(red>=0 && blue>=0){
            if(f && red>=c){
                red-=c;
                c++;
                tans++;
                f=!f;
            }
            else if(!f && blue>=c){
                blue-=c;
                c++;
                tans++;
                f=!f;
            }
            else{
                break;
            }
        }
        return max(ans,tans);
    }
};