map<int,int>d;
class Solution {
    struct com{
    bool operator()(int a,int b) const{
        if(d[a]==d[b]){
            return a>b;
        }
        return d[a]<d[b];
    }};
public:
    vector<int> frequencySort(vector<int>& nums) {
        d.clear();
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            d[nums[i]]++;
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end(),com());
        return v;
    }
};