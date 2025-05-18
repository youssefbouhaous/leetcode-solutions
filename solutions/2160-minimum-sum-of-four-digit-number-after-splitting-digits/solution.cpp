class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        swap(s[1],s[2]);
        string a=s.substr(0,2);
        string b=s.substr(2,2);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return stoi(a)+stoi(b);
    }
};