class Solution {
public:
    int distributeCandies(vector<int>& c) {
        map<int,bool>d;
        int ans=0;
        for(auto x:c){
            if(d[x]==0){
                ans++;
                d[x]=1;
            }
        }
        return min(ans,(int)c.size()/2);
    }
};