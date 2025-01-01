class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        int ans=1;
        sort(i.begin(),i.end());
        int n=i.size();
        int cur=i[0][1];
        for(int y=1;y<n;y++){
            if(cur<=i[y][0]){
                cur=i[y][1];
                ans++;
            }
            else{
                cur=min(cur,i[y][1]);
            }
        }
        return n-ans;
    }
};