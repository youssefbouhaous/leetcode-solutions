class Solution {
    struct comp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) const
    {
        if(a.second-a.first==b.second-b.first){
            return a.first<b.first;
        }
        return a.second-a.first<b.second-b.first;
    }
};
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int a,b;
        a=1e6;
        b=-1e6;
        bool f=true;
        for(int i=0;i<nums.size();i++){reverse(nums[i].begin(),nums[i].end());}
        vector<pair<int,int>>sol;
        while(f){
            for(auto& x:nums){
                if(x.empty()){
                    f=false;
                    break;
                }
            }
            if(!f){
            break;
            }
            a=1e6;
            b=-1e6;
            for(auto& x:nums){
                a=min(x.back(),a);
                b=max(x.back(),b);
                //cout<<a<<' '<<b<<endl;
            }
            sol.push_back({a,b});
            if(a==b){break;}
            for(int i=0;i<nums.size();i++){
                if(nums[i].empty()) continue;
                if(a==nums[i].back()) {
                    nums[i].pop_back();
                }
            }
        }
        sort(sol.begin(),sol.end(),comp());
        return {sol[0].first,sol[0].second};
    }
};