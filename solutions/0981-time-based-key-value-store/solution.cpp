class TimeMap {
public:
    map<string,set<pair<int,string>>>d;
    TimeMap() {
        
    }
    
    void set(string key, string v, int t) {
        d[key].insert({t,v});
    }
    
    string get(string key, int t) {
        if(d[key].empty()){
            return "";
        }
        else{
            auto it=d[key].upper_bound({t,""});
           
            if(it==d[key].end()){
                --it;
                if(it->first>t){
                    return "";
                }
                else{
                    return it->second;
                }
            }
            else{
                if(it->first<=t){
                    return it->second;
                }
                --it;
                if(it->first>t){
                    return "";
                }
                else{
                    return it->second;
                }
            }
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */