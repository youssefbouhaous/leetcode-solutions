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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*>v;
        int count=0;
        ListNode* ans=head;
        while(head!=nullptr){
            v.push_back(head);
            head=head->next;
        }
        while(left<=right){
            swap(v[left-1]->val,v[right-1]->val);
            right--,left++;
        }
        return ans;
    }
};