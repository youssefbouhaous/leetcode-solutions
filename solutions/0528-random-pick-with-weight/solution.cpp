class Solution {
public:
    vector<int>pre;
    int s;
    Solution(vector<int>& w) {
        pre.push_back(0);
        s=0;
        for(auto x:w){
            pre.push_back(pre.back()+x);
            s+=x;
        }    
    }
    
    int pickIndex() {
        int i = rand() % (s)+1;
        int l=1;
        int r=pre.size();
        while(l<r){
            int m=(l+r)/2;
            if(pre[m]>=i){
                r=m;
            }
            else l=m+1;
        }
        return l-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */