class Solution {
public:
    int f(string x){
        
            if(x=="I")
                return 1;
            if(x=="V")
                return 5;
            if(x=="X")
                return 10;
            if(x=="L")
                return 50;
            if(x=="C")
                return 100;
            if(x=="D")
                return 500;
            if(x=="M")
                return 1000;
            return 0;
    }
    int romanToInt(string s) {
        int ss=0;
        int n=s.size()-1;
        int i=n;
        while(i>-1){
            string tm=s.substr(i,1);
            if(i==0){
                ss+=f(tm);
                return ss;
            }
            if(tm=="V" && s[i-1]=='I'){
                ss+=4;
                i-=2;
            }
            else if(tm=="X" && s[i-1]=='I'){
                ss+=9;
                i-=2;
            }
            else if(tm=="L" && s[i-1]=='X'){
                ss+=40;
                i-=2;
            }
            else if(tm=="C" && s[i-1]=='X'){
                ss+=90;
                i-=2;
            }
            else if(tm=="D" && s[i-1]=='C'){
                ss+=400;
                i-=2;
            }
            else if(tm=="M" && s[i-1]=='C'){
                ss+=900;
                i-=2;
            }
            else{
                ss+=f(tm);
                i--;
            }
        }
        return ss;
    }
};