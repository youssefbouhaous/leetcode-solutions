class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2)continue;
            bool f=true;
            int n=s.size();
            int a=0;
            int b=0;
            for(int j=0;j<n/2;j++){
                a+=s[j];
                b+=s[n-j-1];
            }
            if(a==b){
                ans++;
            }
        }
        return ans;
    }
};