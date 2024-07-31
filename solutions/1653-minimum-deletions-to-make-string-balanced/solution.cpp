class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>a(n);
        vector<int>b(n);
        int ac=0;
        int bc=0;
        for(int i=0;i<n;i++){
            b[i]= ac;
            if(s[i]=='b'){
                ac++;
            }
        }
        for(int i=n-1;i>-1;i--){
            a[i]= bc;
            if(s[i]=='a'){
                bc++;
            }
        }
        int ans=n;
        for(int i=0;i<n;i++){
            ans=min(b[i]+a[i],ans);
        }
        return ans;
    }
};