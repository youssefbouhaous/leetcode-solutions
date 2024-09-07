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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* hh;
    map<pair<TreeNode*,ListNode*>,bool>d;
    bool f(ListNode* h,TreeNode* r){
        if(d[{r,h}]){return false;}
        d[{r,h}]=true;
        if(h==nullptr){
            return true;
        }
        if( r==nullptr){
            return false;
        }
        if(h->val==r->val)
        return f(h->next,r->left)||f(h->next,r->right)||f(hh,r->left)||f(hh,r->right);
        
        return f(hh,r->right)||f(hh,r->left);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        hh=head;
        return f(head,root);
    }
};