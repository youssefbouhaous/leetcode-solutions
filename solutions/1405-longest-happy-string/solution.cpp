class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int,char>>q;
        if(a>0)
        q.push({a,'a'});
        if(b>0)
        q.push({b,'b'});
        if(c>0)
        q.push({c,'c'});
        while(!q.empty()){
            int n=ans.size();
            auto t=q.top();
            q.pop();
            if(ans.size()>1 && (ans[n-1]==t.second && ans[n-2]==t.second)){
                if(q.empty()) break;
                auto o=q.top();
                q.pop();
                    ans.push_back(o.second);
                    if(o.first-1>0)
                q.push({o.first-1,o.second});
                q.push(t);
            }
            else{
                ans.push_back(t.second);
                if(t.first-1>0)
                q.push({t.first-1,t.second});
            }
        }
        return ans;
    }
};