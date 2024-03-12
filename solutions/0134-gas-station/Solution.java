class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int ans=0;
        int r=0;
        int id=-1;
        int n=gas.length;
        for(int i=0;i<n;i++){
            if(id!=-1 && ans>=0){
                ans+=gas[i]-cost[i];
            }
            else if(id==-1){
                if(gas[i]-cost[i]>=0){
                    id=i;
                    ans+=gas[i]-cost[i];
                }
                else{
                    r+=gas[i]-cost[i];
                }
            }
            else if(ans<0){
                if(gas[i]-cost[i]>=0){
                    r+=ans;
                    ans=gas[i]-cost[i];
                    id=i;
                }
                else{
                    r+=gas[i]-cost[i];
                }
            }
            else{
                r+=gas[i]-cost[i];
            }
        }
        if(ans+r<0){
            return -1;
        }
        else{
            return id;
        }
    }
}