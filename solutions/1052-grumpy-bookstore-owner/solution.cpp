class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        vector<int>pre(n+1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans+=customers[i];
                pre[i+1]=pre[i];
            }
            else{
                pre[i+1]=pre[i]+customers[i];
            }
        }
        int c=0;
        for(int i=1;i<n+1;i++){
            
            c=max(c,pre[i]-pre[max(0,i-minutes)]);
        }
        return ans+c;
    }
};