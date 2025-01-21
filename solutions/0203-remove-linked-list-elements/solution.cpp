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
    void f(ListNode* node,ListNode* parent,int val){
        if(node==nullptr)return;
        if(node->val==val){
            parent->next=node->next;
            f(parent->next,parent,val);
        }
        else{
            f(node->next,node,val);
        }
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return head;
        while(head!=nullptr){
            if(head->val!=val)break;
            head=head->next;
        }
        if(head==nullptr)return head;
        f(head,head->next,val);
        return head;
    }
};