/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int f(TreeNode node,int l){
        if(node.left==null && node.right==null) return l+1;
        if(node.left==null)return f(node.right,l+1);
        if(node.right==null)return f(node.left,l+1);
        return Math.min(f(node.left,l+1),f(node.right,l+1));
    }
    public int minDepth(TreeNode root) {
        if(root==null)return 0;
        return f(root,0);
    }
}