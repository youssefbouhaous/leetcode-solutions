class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans;
        map<string,int>d;
        for(auto x:arr){
            d[x]++;
        }
        for(auto x:arr){
            if(d[x]==1){
                k--;
                if(k==0){
                    return x;
                }
            }
        }
        return ans;
    }
};