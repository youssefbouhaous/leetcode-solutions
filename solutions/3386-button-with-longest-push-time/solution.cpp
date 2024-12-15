class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& e) {
        int ans=e[0][0];
        int m=e[0][1];
        int n=e.size();
        for(int i=1;i<n;i++){
            //cout<<e[i][1]-e[i-1][1]<<endl;
            if(m<e[i][1]-e[i-1][1]){
                m=e[i][1]-e[i-1][1];
                ans=e[i][0];
            }
            if(m==e[i][1]-e[i-1][1]){
                ans=min(e[i][0],ans);
            }
        }
        //cout<<"ans :"<<ans<<endl;
        return ans;
    }
};