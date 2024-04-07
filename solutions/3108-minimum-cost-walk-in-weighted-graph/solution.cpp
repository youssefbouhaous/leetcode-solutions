class Solution {
    
    map<int,int> parent;
    map<int,int>cost;
    map<int,int>rank;
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    int find_set(int v){
        if(parent[v]==v) return v;
        return parent[v]=find_set(parent[v]);
    }
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            
            int mm=2097151;
            for(int i=0;i<n;i++){
                cost[i]=mm;
                make_set(i);
            }
            vector<int>ans;
            for(int i=0;i<edges.size();i++){
                union_sets(edges[i][0],edges[i][1]);
            }
            for(int i=0;i<edges.size();i++){
                cost[find_set(edges[i][0])]&=edges[i][2];
            }
            for(int i=0;i<query.size();i++){
                if(find_set(query[i][0])!=find_set(query[i][1])){
                    ans.push_back(-1);
                }
                else if(query[i][0]==query[i][1]){
                    ans.push_back(0);
                }
                else
                ans.push_back(cost[find_set(query[i][0])]);
            }
            /*for(int i=0;i<n;i++){
                cout<<"groupe of "<<i<<" "<<find_set(i)<<" cost i:"<<cost[i]<<" cost p:"<<cost[find_set(i)]<<endl;
            }*/
            return ans;
        }
};