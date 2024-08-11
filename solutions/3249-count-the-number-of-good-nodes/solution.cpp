class Solution {
    map<int,vector<int>>tree;
    int ans=0;
    map<int,int>child;
    void f(int node,int p){
        set<int>st;
        for(auto y:tree[node]){
            if(y!=p){
                f(y,node);
                st.insert(child[y]);
                child[node]+=child[y]+1;
            }
        }
        //cout<<"node : "<<node<<" childs : "<<child[node]<<endl;
        if(st.size()<2){
            ans++;
        }
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        for(auto x:edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        f(0,0);
        return ans;
    }
};