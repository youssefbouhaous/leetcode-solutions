class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>>v;
        int n=positions.size();
        for(int i=0;i<n;i++){
            v.push_back({positions[i],healths[i],directions[i],i});
        }    
        sort(v.begin(),v.end());
        stack<vector<int>>h;
        h.push(v[0]);
        for(int i=1;i<n;i++){
            while(!h.empty() && v[i][2]!='R' && v[i][2]!=h.top()[2]){
                if(h.top()[1]==v[i][1]){
                    h.pop();
                    v[i][1]=0;
                    break;
                }
                else if(h.top()[1]>v[i][1]){
                    h.top()[1]--;
                    v[i][1]=0;
                    break;
                }
                else{
                    v[i][1]--;
                    h.pop();
                }
            }
            if(v[i][1]>0){
                h.push(v[i]);
            }
        }
        vector<vector<int>>ans;
        while(!h.empty()){
            ans.push_back({h.top()[3],h.top()[1]});
            h.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>res;
        for(auto x:ans){
            res.push_back(x[1]);
        }
        return res;
    }
};