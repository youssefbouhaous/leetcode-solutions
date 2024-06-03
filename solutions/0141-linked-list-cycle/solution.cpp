/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    map<ListNode*,bool>visited;
    bool hasCycle(ListNode *head) {
        if(head==nullptr ){
            return false;
        }
        if(visited[head]){
            return true;
        }
        visited[head]=true;
        return hasCycle(head->next);
    }
};