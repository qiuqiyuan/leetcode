//The idea is to do a iterative in-order traversal and use 
//a pointer to remember the last poped out one and connect 
//them all together. 

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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *last = NULL;
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
            if(last != NULL){
                last->right = node;
                last->left = NULL;
            }
            last = node;
        }
    }
};

//A recursive solution to the same problem
//The idea is to concatenate the right child to the left one; 
//then have the entire result to be the right child of root. 

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
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        if(!root->left && !root->right) return;
        else if(!root->left && root->right) {
            flatten(root->right); 
            return;
        }else if(root->left && !root->right){
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
        }else{
            TreeNode *lp = root->left; 
            flatten(root->left);
            flatten(root->right);
            while(lp->right != NULL) lp = lp->right;
            lp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
