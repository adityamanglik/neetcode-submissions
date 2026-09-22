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
public:
    int myDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int leftDepth = 0;
        if(root->left != nullptr)
            leftDepth = myDepth(root->left);
        int rightDepth = 0;
        if(root->right != nullptr)
            rightDepth = myDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
    int maxDepth(TreeNode* root) {
        return myDepth(root);        
    }
};
