/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int nn;
    int o=0;
    void f(ListNode* n,ListNode* p,int c){
        if(c==o){
            n->next=nullptr;
            return;
        }
        if(c==o-nn){
            n->next=(p->next);
            return;
        }
        f(n->next,p->next,c+1);
    }
    void help(ListNode* l){
        if(l==nullptr){
            o++;
            return;
        }
        o++;
        help(l->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        help(head);
        if(1==o-n){
            return head->next;
        }
        nn=n;
        f(head,head->next,2);
        return head;
    }
};