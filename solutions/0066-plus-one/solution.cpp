class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int o=1;
        reverse(digits.begin(),digits.end());
        for(int i=0;i<digits.size();i++){
            int r=(digits[i]+o);
            o=r/10;
            digits[i]=r%10;
        }
        if(o!=0){
            digits.push_back(o);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};