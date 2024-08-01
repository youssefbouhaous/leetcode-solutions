class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans=0;
        for(auto x:d){
            if(stoi(x.substr(11,2))>60){
                ans++;
            }
        }
        return ans;
    }
};