class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<n;i++){
            bool f=true;
            int a=i;
            int b=n-i;
            while(a){
                if(a%10==0){
                    f=false;break;}
                    a/=10;
            }
            while(b){
                if(b%10==0){
                    f=false;break;}
                    b/=10;
            }
            if(f){
                return vector<int>{i,n-i};
            }
        }
        return ans;
    }
};