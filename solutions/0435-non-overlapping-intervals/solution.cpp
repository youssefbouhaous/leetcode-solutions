class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(auto x:intervals){
            v.push_back({x[1],x[0]});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int p=v[0].first;
        for(int i=1;i<v.size();i++){
            if(p<=v[i].second){
                p=v[i].first;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};