class Solution {
public:
    string predictPartyVictory(string s) {
        int r=0;
        int d=0;
        deque<char> q;
        for(auto x:s){
            if(x=='R'){
                r++;
            }
            else{
                d++;
            }
            q.push_back(x);
        }
        int dd=0;
        int rr=0;
        while(1){
            if(q.front()=='R' && d==0){
                return "Radiant";
            }
            else if(q.front()=='D' && r==0){
                return "Dire";
            }
            else if(q.front()=='R' ){
                if(rr>0){
                    rr--;
                    q.pop_front();
                    continue;
                }
                d--;
                dd++;
                char tmp=q.front();
                q.pop_front();
                q.push_back(tmp);
            }
            else if(q.front()=='D' ){
                if(dd>0){
                    dd--;
                    q.pop_front();
                    continue;
                }
                r--;
                rr++;
                char tmp=q.front();
                q.pop_front();
                q.push_back(tmp);
            }
            
        }
    }
};