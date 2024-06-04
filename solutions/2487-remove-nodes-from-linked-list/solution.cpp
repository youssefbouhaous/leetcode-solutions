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
    int m=0;
    void dfs(ListNode* node){
        if(node==nullptr){
            return ;
        }
        dfs(node->next);
        m=max(m,node->val);
        //cout<<" m :"<<m<<" val :"<<node->val<<endl;
        if(m>(node->val)){
            //cout<<"o";
            node->val=(node->next)->val;
            node->next=(node->next)->next;
        }
    }
    ListNode* removeNodes(ListNode* head) {
        dfs(head);
        return head;
    }
};