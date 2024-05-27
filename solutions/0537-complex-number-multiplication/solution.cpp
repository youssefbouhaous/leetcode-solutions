#include <string> 
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string num1Real;
        string num1Img;
        string num2Real;
        string num2Img;
        bool flag=false;
        num1.pop_back();
        num2.pop_back();
        for(auto x:num1){
            if(x=='+'){
                flag=true;
                continue;
            }
            if(!flag){
                num1Real.push_back(x);
            }
            else{
                num1Img.push_back(x);
            }
        }
        flag=false;
        for(auto x:num2){
            if(x=='+'){
                flag=true;
                continue;
            }
            if(!flag){
                num2Real.push_back(x);
            }
            else{
                num2Img.push_back(x);
            }
        }
        //cout<<stoi(num1Real)<<endl;
        int a=stoi(num2Real)*stoi(num1Real)-stoi(num2Img)*stoi(num1Img);
        int b=stoi(num1Img)*stoi(num2Real)+stoi(num2Img)*stoi(num1Real);
        string ans;
        
        ans=to_string(a)+"+"+to_string(b)+"i";
        
        return ans;
    }
};