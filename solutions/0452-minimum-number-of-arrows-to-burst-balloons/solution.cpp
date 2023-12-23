class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        priority_queue<pair<int,int>>v;
        for(auto x:points){
            v.push({x[0],x[1]});
        }
        while(v.size()>=2){
            pair<int,int>p=v.top();
            v.pop();
            pair<int,int>p2=v.top();
            v.pop();
            if((p.first<=p2.second && p.second>=p2.first) || (p2.first<=p.second && p2.second>=p.first)){
                pair<int,int>o={max(p.first,p2.first),min(p.second,p2.second)};
                v.push(o);
            }
            else{
                ans++;
                v.push(p2);
            }
        }
        return ans+v.size();
    }
};