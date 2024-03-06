class Solution {
public:
    string validIPAddress(string q) {
       if(q.find(".")!= string::npos){
           
           vector<string>v;
           string tmp;
           for(auto x:q){
               if(x=='.'){
                   v.push_back(tmp);
                   tmp="";
               }
               else{
                   if(!(x>='0' && x<='9')){
                       return "Neither";
                   }
                   tmp.push_back(x);
               }
           }
           
           v.push_back(tmp);
           for(auto x:v){
               if(x==""  ||x.size()>3){
                   return "Neither";
               }
           }
           if(v.size()!=4){
               return "Neither";
           }
           for(auto x:v){
               if(x.size()>1 && x[0]=='0'){
                   return "Neither";
               }
               if(!(stoi(x)<=255 && stoi(x)>=0)){
                   return "Neither";
               }
           }
           return "IPv4";
       }
       else if(q.find(":")!= string::npos){
           vector<string>v;
           string tmp;
           for(auto x:q){
               if(x==':'){
                   v.push_back(tmp);
                   tmp="";
               }
               else if(!((x>='0' && x<='9') ||(x>='a' && x<='f')|| (x>='A' && x<='F'))){
                   return "Neither";
               }
               else{
                   tmp.push_back(x);
               }
           }
           v.push_back(tmp);
           for(auto x:v){
               if(x=="" || x.size()>4){
                   return "Neither";
               }
           }
           if(v.size()!=8){
               return "Neither";
           }
           return "IPv6";
       }
       return "Neither";
    }
};