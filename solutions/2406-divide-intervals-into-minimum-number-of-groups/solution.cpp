class Solution {
public:
    int minGroups(vector<vector<int>>& I) {
        int n=I.size();
        vector<int>pre(1e6+7);
        for(auto x:I){
            pre[x[0]]++;
            pre[x[1]+1]--;
        }
        int ans=0;
        for(int i=1;i<=1e6;i++){
            pre[i]=pre[i-1]+pre[i];
            ans=max(ans,pre[i]);
        }
        return ans;
    }
};