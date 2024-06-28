class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>v;
        for(auto y:arr){
            v.push_back({abs(y-x),y});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        int kk=0;
        for(auto y:v){
            kk++;
            ans.push_back(y.second);
            if(kk==k){
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};