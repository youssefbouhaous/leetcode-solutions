class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        priority_queue<int,vector<int>,greater<int>>q;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }   
        sort(v.begin(),v.end());
        long long int res=0LL;
        long long int sum=0LL;
        long long int mul=0LL;
        for(int i=n-1;i>-1;i--){
            if(q.size()<k){
                sum+=v[i].second;
                mul=v[i].first;
                q.push(v[i].second);
            }
            else{
                int a=q.top();
                q.pop();
                q.push(v[i].second);
                sum=sum-a+v[i].second;
                mul=v[i].first;
            }
            if(q.size()==k){
                res=max(res,sum*mul);
            }
        }
        return res;
    }
};