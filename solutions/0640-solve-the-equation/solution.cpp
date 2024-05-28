class Solution {
public:
    string solveEquation(string equation) {
        int x=0;
        int r=0;
        int i=0;
        while(equation[i]!='='){
            if(equation[i]=='x'){
                x++;
                i++;
            }
            else if(equation[i]=='-' && equation[i+1]=='x'){
                x--;
                i+=2;
            }
            else if(equation[i]=='+' && equation[i+1]=='x'){
                x++;
                i+=2;
            }
            else{
                string num;
                num.push_back(equation[i]);
                i++;
                while(equation[i]!='-' && equation[i]!='+' && equation[i]!='=' && equation[i]!='x'){
                    num.push_back(equation[i]);
                    i++;
                }
                if(equation[i]=='x'){
                    x+=stoi(num);
                    i++;
                    continue;
                }
                cout<<num<<" ";
                cout<<"r here f :"<<r<<endl;
                r-=stoi(num);
            }
        }
        i++;
        while(i<equation.size()){
            if(equation[i]=='x'){
                x--;
                i++;
            }
            else if(i+1<equation.size() && equation[i]=='-' && equation[i+1]=='x'){
                x++;
                i+=2;
            }
            else if(i+1<equation.size() && equation[i]=='+' && equation[i+1]=='x'){
                x--;
                i+=2;
            }
            else{
                string num;
                num.push_back(equation[i]);
                i++;
                while(i<equation.size() && equation[i]!='-' && equation[i]!='+' && equation[i]!='=' && equation[i]!='x'){
                    num.push_back(equation[i]);
                    i++;
                }
                if(i<equation.size() && equation[i]=='x'){
                    x-=stoi(num);
                    i++;
                    continue;
                }
                r+=stoi(num);
                cout<<"r here s :"<<r<<endl;
            }
        }
        cout<<r<<" "<<x<<endl;
        if(x==0 && r==0){
            return "Infinite solutions";
        }
        else if(x==0 && r!=0){
            return "No solution";
        }
        else{
            return "x="+to_string(r/x);
        }
    }
};