class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>suf(n);
        vector<int>pre(n);
        pre[0]=h[0];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],h[i]);
        }
        suf[n-1]=h[n-1];
        for(int i=n-2;i>-1;i--){
            suf[i]=max(suf[i+1],h[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int tmp=min(pre[i],suf[i]);
            if(tmp>h[i]){
                ans+=tmp-h[i];
            }
        }
        return ans;
    }
};