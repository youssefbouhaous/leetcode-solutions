class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        deque<int>dq;
        for(auto x:costs){
            dq.push_back(x);
        }
        int cc=c;
        while(!dq.empty() && cc--){
            q.push({dq.front(),0});
            dq.pop_front();
        }
        cc=c;
        while(!dq.empty() && cc--){
            q.push({dq.back(),1});
            dq.pop_back();
        }
        long long ans=0;
        while(k--){
            int p=q.top().second;
            ans+=q.top().first;
            q.pop();
            if(!dq.empty()){
                if(p==0){
                    q.push({dq.front(),0});
                    dq.pop_front();
                }
                else{
                    q.push({dq.back(),1});
                    dq.pop_back();
                }
            }
        }
        return ans;
    }
};