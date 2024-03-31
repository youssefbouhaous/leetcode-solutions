class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char t) {
        int l=0;
        int r=a.size()-1;
        int ans=a[0];
        while(l<=r){
            int m=(l+r)/2;
            if(a[m]>t){
                ans=a[m];
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};