class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        if(n==0){
            return t.size();
        }
        int ans=0;
        priority_queue<int>q;
        map<char,int>mp;
        for(auto c:t)mp[c]++;
        for(auto x:mp)q.push(x.second);
        while(!q.empty()){
            int cnt=0;
            int cy=n+1;
            vector<int>tmp;
            while(cy-- && !q.empty()){
                if(q.top()>1){
                    tmp.push_back(q.top()-1);
                }
                q.pop();
                cnt++;
            }
            for(auto x:tmp)q.push(x);
            ans+=(q.empty())?cnt:n+1;
        }

        return ans;
    }
};