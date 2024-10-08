class Solution {
public:
    int minSwaps(string s) {
        int o=0;
        if(s.empty()) return o;
        int c=0;
        for(auto x:s){
            if(x=='['){
                c++;
            }
            else{
                c--;
            }
            if(c<0){
                o++;
                c++;
            }
        }
        return (o+1)/2;
    }
};