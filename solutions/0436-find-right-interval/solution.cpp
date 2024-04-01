class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& I) {
        vector<int>ans;
        vector<pair<int,int>>e;
        int n=I.size();
        for(int i=0;i<n;i++){
            e.push_back({I[i][0],i});
        }
        sort(e.begin(),e.end());
        for(int i=0;i<n;i++){
            int l=0;
            int r=n-1;
            int anss=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(e[m].first>=I[i][1]){
                    anss=e[m].second;
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            ans.push_back(anss);
        }
        return ans;
    }
};