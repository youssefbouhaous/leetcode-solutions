class Solution {
public:
    bool haveConflict(vector<string>& a, vector<string>& b) {
        int am1=stoi(a[0].substr(0,2))*60+stoi(a[0].substr(3,2));
        int am2=stoi(a[1].substr(0,2))*60+stoi(a[1].substr(3,2));
        int bm1=stoi(b[0].substr(0,2))*60+stoi(b[0].substr(3,2));
        int bm2=stoi(b[1].substr(0,2))*60+stoi(b[1].substr(3,2));
        return (am1<=bm1 && bm1 <=am2) ||((am1<=bm2 && bm2 <=am2)) || (bm1<=am1 && am1 <=bm2)
        || (bm1<=am2 && am2 <=bm2);
    }
};