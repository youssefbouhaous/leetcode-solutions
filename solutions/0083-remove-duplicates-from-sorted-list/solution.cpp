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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* ans=head;
        while(ans->next!=nullptr){
            if(ans->next->val==ans->val){
                ans->next=ans->next->next;
            }
            else{
                ans=ans->next;
            }
        }
        return head;
    }
};