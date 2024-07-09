class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double t=0;
        double at=0;
        for(auto x:customers){
            //cout<<"before"<<at<<endl;
            if(x[0]>=at){
                t+=x[1];
                at=x[0]+x[1];
            }
            else{
                t+=x[1]+at-x[0];
                at=at+x[1];
            }
            //cout<<"after"<<at<<endl;
        }
        return t/customers.size();
    }
};