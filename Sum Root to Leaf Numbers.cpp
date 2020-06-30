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
    
    void inorder(TreeNode* t, vector<int> &val, int &sum){
        if(!t)
            return;
        if(!t->left && !t->right){
            int temp = 0;
            for(int i=0; i<val.size(); i++){
                temp = temp * 10 + val[i]; 
            } 
            temp = temp * 10 + t->val;
            sum += temp;
            return;
        }
        val.push_back(t->val);
        inorder(t->left, val, sum);
        inorder(t->right, val, sum);
        val.erase(val.begin()+val.size()-1);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        int sum = 0;
        vector<int> val;
        inorder(root, val, sum);
        return sum;
    }
};
