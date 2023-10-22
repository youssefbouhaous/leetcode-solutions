class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        map<int,bool>hasp;
        for(int i=0;i<edges.size();i++){
            hasp[edges[i][1]]=true;
        }
        for(int i=0;i<n;i++){
            if(hasp[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};