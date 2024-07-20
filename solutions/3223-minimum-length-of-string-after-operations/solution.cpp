class Solution {
public:
    int minimumLength(string s) {
        map<char,int>d;
        for(auto x:s){
            d[x]++;
        }
        int ans=0;
        for(auto x:d){
            if(x.first<3){
                ans+=x.second;
            }
            else{
                if(x.second%2==0){
                    ans+=2;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};