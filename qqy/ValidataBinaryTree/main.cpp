//This version of the code is not necessary right
//Especially gst and smst should not be the right approach

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
    int gst(TreeNode *root){
        TreeNode *node = root; 
        while(node->right) node = node->right;
        if(node->left && node->left->val > node->val) return node->left->val;
        else return node->val;
    }
    int smst(TreeNode *root){
        TreeNode *node = root; 
        while(node->left) node = node->left;
        if(node->right && node->right->val < node->val) return node->right->val;
        else return node->val;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(!root->left && !root->right) {
            return true;
        }else if(!root->left && root->right){
            return root->val < smst(root->right) && isValidBST(root->right);
        }else if(root->left && !root->right){
            return root->val > gst(root->left) && isValidBST(root->left);
        }else {
            return root->val > gst(root->left) && root->val < smst(root->right) &&
            isValidBST(root->left) && isValidBST(root->right);
        }
    }
};
