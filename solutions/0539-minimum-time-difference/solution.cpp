class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int>toMin;
        for(auto x:t){
            int tmp=(x[0]-'0')*600+(x[1]-'0')*60+(x[3]-'0')*10+(x[4]-'0');
            toMin.push_back(tmp);
        }
        int ans=abs(toMin[0]-toMin[1]);
        for(int i=0;i<toMin.size();i++){
            for(int j=0;j<toMin.size();j++){
                if(i!=j)
                ans=min(min(abs(toMin[i]-toMin[j]),1440-abs(toMin[i]-toMin[j])),ans);
            }
        }
        cout<<010<<endl;
        cout<<toMin[0]<<endl;
        return ans;
    }
};