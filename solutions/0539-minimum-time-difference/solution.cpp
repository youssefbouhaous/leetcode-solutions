class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int>toMin;
        for(auto x:t){
            int tmp=(x[0]-'0')*600+(x[1]-'0')*60+(x[3]-'0')*10+(x[4]-'0');
            toMin.push_back(tmp);
        }
        sort(toMin.begin(),toMin.end());
        int ans=abs(toMin[0]-toMin[1]);
        for(int i=0;i<toMin.size();i++){
            int j=i+1;
            j=j%toMin.size();
            ans=min(min(abs(toMin[i]-toMin[j]),1440-abs(toMin[i]-toMin[j])),ans);
            j=i-1;
            if(j<0){
                j=toMin.size()-1;
            }
            ans=min(min(abs(toMin[i]-toMin[j]),1440-abs(toMin[i]-toMin[j])),ans);
        }
        return ans;
    }
};