class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>s(n);
        bitset<32>t(n);
        for(int i=0;i<32;i++){
            s[i]=t[31-i];
        }
        int ans=(int)(s.to_ulong());
        return ans;
    }
};