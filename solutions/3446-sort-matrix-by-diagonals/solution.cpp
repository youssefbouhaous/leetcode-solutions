class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int x=i,y=0;
            vector<int>tmp;
            while(x<n && y<n){
                tmp.push_back(grid[x][y]);
                x++,y++;
            }
            sort(tmp.rbegin(),tmp.rend());
            x=i,y=0;
            int o=0;
            while(x<n && y<n){
                ans[x++][y++]=tmp[o++];
            }
        }
        for(int i=1;i<n;i++){
            int x=0,y=i;
            vector<int>tmp;
            while(x<n && y<n){
                tmp.push_back(grid[x][y]);
                x++,y++;
            }
            sort(tmp.begin(),tmp.end());
            x=0,y=i;
            int o=0;
            while(x<n && y<n){
                ans[x++][y++]=tmp[o++];
            }
        }
        return ans;
    }
};
