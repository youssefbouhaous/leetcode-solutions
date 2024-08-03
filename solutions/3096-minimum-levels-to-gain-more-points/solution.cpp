class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int ans=0;
        int n=possible.size();
        for(int i=0;i<n;i++){
            ans+= (possible[i]==1) ? 1 : -1;
        }
        int a=0;
        for(int i=0;i<n-1;i++){
            a+= (possible[i]==1) ? 1 : -1;
            if(a>ans-a)
                return i+1;
        }
        return -1;
    }
};