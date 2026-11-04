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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        vector<int> currValues;
        currValues.push_back(root->val);
        queue<TreeNode*> currLevel;
        if(root->left != nullptr)
            currLevel.push(root->left);
        if(root->right != nullptr)
            currLevel.push(root->right);
        ans.push_back(currValues);
        currValues.clear();
        while(currLevel.size() != 0){
            // drain the current nodes
            queue<TreeNode*> newLevel;
            while(currLevel.size() != 0){
                TreeNode* node = currLevel.front();
                currLevel.pop();
                currValues.push_back(node->val);
                if(node->left != nullptr)
                    newLevel.push(node->left);
                if(node->right != nullptr)
                    newLevel.push(node->right);
            }
            // replace the new node list end
            ans.push_back(currValues);
            currValues.clear();
            currLevel = newLevel;
        }
        return ans;
    }
};
