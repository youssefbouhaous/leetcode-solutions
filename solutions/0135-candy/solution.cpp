class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1] && ans[i]<=ans[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-2;i>-1;i--){
            if(ratings[i]>ratings[i+1] && ans[i]<=ans[i+1]){
                ans[i]=ans[i+1]+1;
            }
        }
        int s=0;
        for(auto x:ans){
            s+=x;
        }
        return s;
    }
};