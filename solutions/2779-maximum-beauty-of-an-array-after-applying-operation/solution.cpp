class Solution {
public:
    struct Comparator {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if(a.first==b.first){
                return a.second > b.second;
            }
            return a.first<b.first;
        }
    };

    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>l;
        for(int i=0;i<n;i++){
            int a,b;
            a=nums[i]-k;
            b=nums[i]+k;
            l.push_back({a,1});
            l.push_back({b,-1});
        }
        sort(l.begin(),l.end(),Comparator());
        int ans=0;
        int c=0;
        for(int i=0;i<l.size();i++){
            c+=l[i].second;
            ans=max(ans,c);
        }
        return ans;
    }
};