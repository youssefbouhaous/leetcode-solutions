class MyCalendar {
public:
    vector<pair<int,int>>books;
    MyCalendar() {
        
    }
    
    bool book(int a, int b) {
        for(auto x:books){
            int c=x.first;
            int d=x.second;
            if((c<=a && a<d)||(c<b&&b<d)||(a<=c&&c<b)||(a<d&&d<b)){
                return false;
            }
        }
        books.push_back({a,b});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */