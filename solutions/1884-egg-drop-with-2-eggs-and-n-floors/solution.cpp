class Solution {
public:
    int twoEggDrop(int n) {
        double ans=ceil((-1+sqrt(1+8*((double)n)))/2.0);
        return ans;
    }
};