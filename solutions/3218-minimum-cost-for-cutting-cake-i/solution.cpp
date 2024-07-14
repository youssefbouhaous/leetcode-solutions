class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        int ans=0;
        for(auto x:v){
            ans+=x;
        }
        for(auto y:h){
            ans+=y;
        }
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(h[i]>v[j]){
                    ans+=v[j];
                }
                else{
                    ans+=h[i];
                }
            }
        }
        return ans;
    }
};