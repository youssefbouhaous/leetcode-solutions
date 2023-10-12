class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,vector<int>> v;
        map<int,vector<int>> v2;
        for(auto x:trust){
            v[x[0]].push_back(x[1]);
            v2[x[1]].push_back(x[0]);
        }
        int ans=-1;
        int m=0;
        for(int i=1;i<=n;i++){
            if(v2[i].size()==n-1 && v[i].size()==0){
                m++;
                ans=i;
            }
        }
        if(m!=1){
            return -1;
        }
        return ans;
    }
};