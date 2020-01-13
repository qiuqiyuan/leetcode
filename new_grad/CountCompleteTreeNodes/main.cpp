
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
    bool perfect(TreeNode *root, int &n){
        if(root == NULL) {
            n = 0;
            return true;
        }
        int left_h = 0, right_h = 0;
        TreeNode *nodel = root, *noder = root;
        while(nodel) {left_h++ ; nodel = nodel->left;}
        while(noder) {right_h++; noder = noder->right;}
        if(left_h == right_h) {
            n  = pow(2, left_h) - 1;
            return true;
        }
        n = 0;
        return false;
    }
public:
    int countNodes(TreeNode* root) {
        int n = 0;
        if(perfect(root, n)) return n;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
