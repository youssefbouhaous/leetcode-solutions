class Solution {
public:

    void changeDirection(int &x,int&y,int& d){
        if(d==0){
            y++;
        }
        if(d==1){
            x++;
        }
        if(d==2){
            y--;
        }
        if(d==3){
            x--;
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        set<pair<int,int>>obs;
        for(auto x:obstacles){
            obs.insert({x[0],x[1]});
        }
        int maxd=0;
        int direction=0;
        
        for(auto k:commands){
            if(k==-1){
                direction++;
                direction=direction%4;
            }
            else if(k==-2){
                direction--;
                direction=(direction+4)%4;
            }
            else{
                for(int i=0;i<k;i++){
                    int tmpx=x;
                    int tmpy=y;
                    changeDirection(x,y,direction);
                    if(obs.count({x,y})){
                        x=tmpx;
                        y=tmpy;
                    }
                    //cout<<x<<" "<<y<<" d :"<<direction<<endl;
                    maxd=max(x*x+y*y,maxd);
                }
            }
        }
        return maxd;
    }
};