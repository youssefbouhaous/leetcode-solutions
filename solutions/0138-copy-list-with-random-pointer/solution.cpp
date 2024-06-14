/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* begin = new Node(head->val);
        Node* ans=begin;
        map<Node*,Node*>d;
        map<Node*,Node*>d2;
        d[begin]=head;
        d2[head]=begin;
        head=head->next;
        while(head!=nullptr){
            Node* nxt=new Node(head->val);
            d[nxt]=head;
            d2[head]=nxt;
            begin->next=nxt;
            begin=nxt;
            head=head->next;
        }
        for(auto x:d){
            x.first->random=d2[x.second->random];
        }
        return ans;
    }
};