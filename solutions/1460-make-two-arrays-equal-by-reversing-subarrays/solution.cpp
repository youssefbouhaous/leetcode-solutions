class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};