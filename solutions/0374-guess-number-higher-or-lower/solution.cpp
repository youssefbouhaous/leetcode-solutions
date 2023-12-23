/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int o=guess(n/2);
        long long  r=n;
        long long l=0;
        while(l<=r){
            if(guess((l+r)/2)==0){
                return (l+r)/2;
            }
            else if(guess((l+r)/2)==-1){
                r=(l+r)/2-1;
            }
            else{
                l=(l+r)/2+1;
            }
        }
        return (l+r)/2;
    }
};