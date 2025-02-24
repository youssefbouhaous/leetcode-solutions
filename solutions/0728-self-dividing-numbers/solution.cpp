class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            bool f=true;
            int tmp=i;
            while(tmp){
                if(tmp%10==0 || i%(tmp%10)!=0)f=false;
                if(!f)break;
                tmp/=10;
            }
            if(f)ans.push_back(i);
        }
        return ans;
    }
};