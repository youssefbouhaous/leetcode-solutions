/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int m = (l+r)/2;
        int ans = m;
        while(l<=r){
            m=(r-l)/2+l;
            if(isBadVersion(m)){
                if(!isBadVersion(m-1))return m;
                ans = m;
                r = m-1;
            }else{
                if(isBadVersion(m+1))return m+1;
                l =m+1;
            }
        }
        return ans;
    }
}