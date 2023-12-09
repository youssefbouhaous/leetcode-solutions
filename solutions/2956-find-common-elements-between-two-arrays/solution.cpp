class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& a, vector<int>& b) {
        vector<int>ans(2);
        int c=0;
        for(auto x:a){
            for(auto y:b){
                if(x==y){
                    c++;
                    break;
                }
            }
        }
        ans[0]=c;
        c=0;
        for(auto x:b){
            for(auto y:a){
                if(x==y){
                    c++;
                    break;
                }
            }
        }
        ans[1]=c;
        return ans;
    }
};