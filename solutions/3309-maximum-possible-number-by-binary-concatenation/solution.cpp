class Solution {
    struct comp {
    bool operator()(string a, string b) const {
        int n=a.size();
        int m=b.size();
        for(int i=0;i<min(n,m);i++){
            if(a[i]<b[i]) return false;
            else if(a[i]>b[i]) return true;
        }
        return a+b>b+a;
    }
    };
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string>strs;
        for(auto x:nums){
            strs.push_back(bitset<32>(x).to_string());
        }
        for(int i=0;i<strs.size();i++ ){
            bool f=false;
            int o=stoi(strs[i]);
            strs[i]=to_string(o);
        }
        sort(strs.begin(),strs.end(),comp());
        string tmp;
        for(auto x:strs){
            tmp+=x;
        }
        int ans=stoi(tmp, nullptr, 2);
        return ans;
    }
};