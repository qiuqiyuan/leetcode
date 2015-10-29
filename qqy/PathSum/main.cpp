
//The idea is to check a different sum every level
//This version is a bit verbose in that it handles four cases.
//In fact we only need two.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(!root->left && !root->right){
            return sum == root->val;   
        }else if(root->left && !root->right){
            return hasPathSum(root->left, (sum - root->val));
        }else if(!root->left && root->right){
            return hasPathSum(root->right, (sum - root->val));
        }else{
            return hasPathSum(root->left, (sum - root->val)) || 
            hasPathSum(root->right, (sum - root->val));
        }
    }
};

//This avoids verbosity
//Because if root == NULL, the program returns false.
//The big OR is later handled automatically
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(!root->left && !root->right){
            return sum == root->val; 
        }else{
            return hasPathSum(root->left, (sum - root->val)) || 
            hasPathSum(root->right, (sum - root->val));
        }
    }
};
