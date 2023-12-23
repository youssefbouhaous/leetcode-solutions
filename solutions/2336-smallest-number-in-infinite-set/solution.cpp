class SmallestInfiniteSet {
public:
    priority_queue <int, vector<int>, greater<int>>q;
    map<int,bool>v;
    set<int>st;
    SmallestInfiniteSet() {
       st.insert(1);
    }
    
    int popSmallest() {
        int o=*st.begin();
        st.erase(o);
        if(v[o]!=true){
            st.insert(o+1);
            v[o]=true;
        }
        return o;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */