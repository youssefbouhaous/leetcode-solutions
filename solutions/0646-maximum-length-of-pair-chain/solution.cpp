class Solution {
public:

    struct comp {
        bool operator()(const vector<int>&a,const vector<int>&b){
            if(a[1]!=b[1]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        }
    };  
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp());
        int ans=1;
        int b=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>b){
                b=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};