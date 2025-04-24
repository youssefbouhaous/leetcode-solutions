class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<vector<int>,int>vis;
        vector<vector<int>>v;
        vector<int>b=cells;
        v.push_back(cells);
        vis[cells]=0;
        for(int i=1;i<=n;i++){
            vector<int>d={0};
            for(int j=1;j<7;j++){
                if(b[j-1]==b[j+1]){
                    d.push_back(1);
                }
                else{
                    d.push_back(0);
                }
            }
            d.push_back(0);
            if(vis[d]){
                int start=vis[d];
                int len=i-start;
                return v[start+(n-start)%len];
            }
            vis[d]=i;
            v.push_back(d);
            b=d;
        }
        return v.back();
    }
};