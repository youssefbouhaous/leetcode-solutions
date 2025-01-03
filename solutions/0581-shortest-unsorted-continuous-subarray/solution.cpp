class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>>q;
        q.push({nums[0],0});
        int mn=n;
        int mx=-1;
        for(int i=1;i<n;i++){
            if(nums[i]>=q.top().first){
                q.push({nums[i],i});
            }
            else{
                //vector<int>tmp;
                mx=max(mx,i);
                int u=i;
                pair<int,int> mxx={nums[i],i};
                while(!q.empty() && nums[i]<q.top().first){
                    mn=min(mn,q.top().second);
                    if(mxx.first<q.top().first){
                        mxx=q.top();
                    }
                    q.pop();
                }
                q.push(mxx);
                /*for(auto x:tmp){
                    q.push(x);
                }*/
            }
        }
        if(mn<=mx){
            return mx-mn+1;
        }
        return 0;
    }
};