class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& m, vector<int>& info) {
        unordered_map<int,vector<int>>g;
        for(int i=0;i<n;i++){
            g[m[i]].push_back(i);
        }
        queue<int>q;
        q.push(head);
        vector<int>d(n);
        int ans=0;
        while(!q.empty()){
            int nxt=q.front();q.pop();
            for(auto y:g[nxt]){
                d[y]=d[nxt]+info[nxt];
                ans=max(ans,d[y]);
                q.push(y);
            }
        }
        return ans;
    }
};