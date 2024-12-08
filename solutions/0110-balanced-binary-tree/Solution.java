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
    boolean ff=true;
    int f(TreeNode node,int l){
        if(node==null){
            return l;
        }
        int a=f(node.left,l+1);
        int b=f(node.right,l+1);
        if(Math.abs(a-b)>1)ff=false;
        return Math.max(a,b);
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        f(root,0);
        return ff;
    }
}