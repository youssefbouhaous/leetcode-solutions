class CustomStack {
    vector<int>v;
    int mx;
public:
    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(v.size()<mx){
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.empty())return -1;
        int r=v.back();
        v.pop_back();
        return r;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min((int)v.size(),k);i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */