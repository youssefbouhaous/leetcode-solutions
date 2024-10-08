class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        string q;
        for(auto x:s){
            if(x=='[') q.push_back(x);
            else{
                if(!q.empty()) q.pop_back();
                else{
                    ans++;
                }
            }
        }
        return (ans+1)/2;
    }
};