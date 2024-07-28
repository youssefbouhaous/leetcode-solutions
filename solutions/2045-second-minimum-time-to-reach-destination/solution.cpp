class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> d1(n+1,numeric_limits<int>::max()),d2(n+1,numeric_limits<int>::max()),freq(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        minh.push({0,1});
        d1[1]=0;
        while(!minh.empty()){
            auto [t,node]=minh.top();
            minh.pop();
            freq[node]++;
            if(freq[node]==2 && node==n) return t;
            if((t/change)%2)
                t=change*(t/change+1)+time;
            else
                t=t+time;
            for(auto& to:adj[node]){
                if(freq[to]==2) continue;
                if(d1[to]>t){
                    d2[to]=d1[to];
                    d1[to]=t;
                    minh.push({t,to});
                }
                else if(d2[to]>t && d1[to]!=t){
                    d2[to]=t;
                    minh.push({t,to});
                }
            }
        }
        return 0;
    }
};