class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<int>q;
        int n=skills.size();
        int mx=skills[0];
        int ans=0;
        for(int i=0;i<n;i++){
            q.push_back(i);
            if(skills[i]>mx){
                ans=i;
                mx=skills[i];
            }
        }
        if(k>=n){
            return ans;
        }
        int p=0;
        while(true){
            int cur=q.front();
            q.pop_front();
            if(skills[cur]<skills[q.front()]){
                q.push_back(cur);
                p=1;
                if(p==k){
                    return q.front();
                }
            }
            else{
                p++;
                if(p==k){
                    return cur;
                }
                q.push_back(q.front());
                q.pop_front();
                q.push_front(cur);
            }
        }
    }
};