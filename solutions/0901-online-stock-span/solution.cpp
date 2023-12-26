class StockSpanner {
public:
    stack<pair<int,int>>st;
    int n;
    StockSpanner() {
        n=1;
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        else if(price<st.top().first){
            st.push({price,1});
            return 1;
        }
        else{
            int m=1;
            while(!st.empty() && price>=st.top().first){
                m+=st.top().second;
                st.pop();
            }
            st.push({price,m});
            return m;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */