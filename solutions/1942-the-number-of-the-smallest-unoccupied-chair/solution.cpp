class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<pair<int,int>>events;
        for(int i=0;i<n;i++){
            events.push_back({times[i][0],i});
            events.push_back({times[i][1],~i});
        }
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>av;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>oc;
        for(int i=0;i<n;i++) av.push(i);
        for(auto& e:events){
            int t=e.first;
            int id=e.second;
            //cout<<id<<endl;
            while(!oc.empty() && oc.top().first<=t){
                av.push(oc.top().second);
                oc.pop();
            }
            if(id>=0){
            if(id==targetFriend){
                cout<<"wow";
                return av.top();
            }
            oc.push({times[id][1],av.top()});
            av.pop();
            }
        }
        return -1;
    }
};