class Solution {
public:
    int integerReplacement(long long n) {
        if(n==1) return 0;
        if(n==2) return 1;
        if(n%2==0){
            return 1+integerReplacement(n/2);
        }
        int a=0;
        int b=0;
        long long  x=n-1;
        long long y=(long long)n+1;
        while(x%2){
            a++;
            x/=2;
        }
        while(y%2){
            b++;
            y/=2;
        }
        if(a>b){
            return 1+integerReplacement(n-1);
        }
        else if(a<b){
            return 1+integerReplacement(n+1);
        }
        return 1+min(integerReplacement(n-1),integerReplacement(n+1));
    }
    int integerReplacement(int n){
        return integerReplacement((long long) n);
    }
};