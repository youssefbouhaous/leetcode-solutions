class RecentCounter {
public:
    vector<int>v;
    RecentCounter() {
        
    }
    int ping(int t) {
        v.push_back(t);
        int ans=0;
        int r=v.back();
        if(v.size()>0){
            ans++;
        }
        for(int i=v.size()-2;i>-1;i--){
            if(r-v[i]<=3000){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */