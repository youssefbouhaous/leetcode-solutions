class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int kk) {
        long long int total=0;
        for(int i=0;i<chalk.size();i++) total+=chalk[i];
        long long int k=((long long int)kk)%total;
        if(k<chalk[0]) return 0;
        k-=chalk[0];
        for(int i=1;i<chalk.size();i++){
            if(k<chalk[i]) return i;
            k-=chalk[i];
        }
        return 0;
    }
};