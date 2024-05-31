class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<string>tokens;
        for(auto x:token){
            tokens.push(x);
        }
        set<string>ops={"+","-","/","*"};
        for(auto x:token){
            if(ops.count(x)){
                int b=stoi(tokens.top());
                tokens.pop();
                int a=stoi(tokens.top());
                tokens.pop();
                int res=0;
                if(x=="+"){
                    res=a+b;
                }
                if(x=="-"){
                    res=a-b;
                }
                if(x=="*"){
                    res=a*b;
                }
                if(x=="/"){
                    res=a/b;
                }
                tokens.push(to_string(res));
            }
            else{
                tokens.push(x);
            }
        }
        return stoi(tokens.top());
    }
};