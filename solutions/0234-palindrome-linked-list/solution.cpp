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
    bool isPalindrome(ListNode* head) {
        vector<int>a;
        vector<int>b;
        while(head!=nullptr){
            a.push_back(head->val);
            b.push_back(head->val);
            head=head->next;
        }
        reverse(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
};