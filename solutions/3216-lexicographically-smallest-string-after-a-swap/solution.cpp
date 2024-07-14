class Solution {
public:
    string getSmallestString(string s) {
        vector<string>v;
        int n=s.size();
        v.push_back(s);
        for(int i=0;i<n-1;i++){
            if((s[i]-'0')%2==(s[i+1]-'0')%2){
                swap(s[i],s[i+1]);
                v.push_back(s);
                swap(s[i],s[i+1]);
            }
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};