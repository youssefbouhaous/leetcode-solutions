// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadVersion(int n) {
        
        long l=1;
        long r=n;
        long m=(l+r)/2;
        while(true){
            m=(l+r)/2;
            if(isBadVersion(m) && !isBadVersion(m-1)){
                return m;
            }
            else if(!isBadVersion(m) && isBadVersion(m+1)){
                return m+1;
            }
            else if(isBadVersion(m)){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return m;
    }
};