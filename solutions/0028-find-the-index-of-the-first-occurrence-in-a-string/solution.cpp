class Solution {
public:
    int strStr(string h, string s) {
        if(h.find(s)>=h.size()){
            return -1;
        }
        return h.find(s);
    }
};