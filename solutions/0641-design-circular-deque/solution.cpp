class MyCircularDeque {
    deque<int>q;
    int k;
    int c=0;
public:
    MyCircularDeque(int kk) {
       k=kk; 
    }
    
    bool insertFront(int value) {
        if(q.size()==k){
            return false;
        }
        q.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(q.size()==k) return false;
        q.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(q.size()==0) return false;
        q.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(q.size()==0)return false;
        q.pop_back();
        return true;
    }
    
    int getFront() {
        return (q.empty())? -1:q.front();
    }
    
    int getRear() {
        return (q.empty())?-1:q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size()==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */