class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        while(s.size()<((1<<n)-1)){
            string tmp=s;
            for(int i=0;i<s.size();i++){
                s[i]= (s[i]=='0') ? '1' : '0';
            }
            reverse(s.begin(),s.end());
            s=tmp+"1"+s;
        }
        return s[k-1];
    }
};