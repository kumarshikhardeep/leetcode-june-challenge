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
    
    void inorder(TreeNode* t, set<TreeNode*> &visited){
        if(t){
            visited.insert(t);
        }
        else
            return;
        inorder(t->left, visited);
        inorder(t->right, visited);
    }
    
    int countNodes(TreeNode* root) {
        set<TreeNode*> visited;
        inorder(root, visited);
        return visited.size();
    }
};
